#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	return 0;
}

static int __init add_wait_queue_exclusive_init(void)
{
	pid_t			pid1,	pid2,	pid3;
	struct pid		*kpid1,	*kpid2,	*kpid3;
	struct task_struct	*task1,	*task2,	*task3;
	wait_queue_head_t	head;
	wait_queue_t		data1,	data2,	data3, *curr,	*next;
	int wait_queue_num;
	printk(KERN_INFO "add_wait_queue_exclusive_init\n");

	pid1 = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	pid2 = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	pid3 = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	printk(KERN_INFO "kpid1 :%d, kpid2 :%d, kpid3 :%d\n",
			pid1, pid2, pid3);

	kpid1 = find_get_pid(pid1);
	kpid2 = find_get_pid(pid2);
	kpid3 = find_get_pid(pid3);

	task1 = pid_task(kpid1, PIDTYPE_PID);
	task2 = pid_task(kpid2, PIDTYPE_PID);
	task3 = pid_task(kpid3, PIDTYPE_PID);

	init_waitqueue_head(&head);

	init_waitqueue_entry(&data1, task1);
	init_waitqueue_entry(&data2, task2);
	init_waitqueue_entry(&data3, task3);

	add_wait_queue_exclusive(&head, &data1);
	add_wait_queue_exclusive(&head, &data2);
	add_wait_queue(&head, &data3);
#if 0
#define list_for_each_entry_safe(pos, n, head, member)			\
	for (pos = list_entry((head)->next, typeof(*pos), member),	\
		n = list_entry(pos->member.next, typeof(*pos), member);	\
	     &pos->member != (head); 					\
	     pos = n, n = list_entry(n->member.next, typeof(*n), member))
#endif
	wait_queue_num = 0;
	list_for_each_entry_safe(curr, next, &head.task_list, task_list) {
		wait_queue_num++;
		printk(KERN_INFO "curr->pid : %d\n",
				((struct task_struct *)curr->private)->pid);
		printk(KERN_INFO "curr->state : %ld\n",
				((struct task_struct *)curr->private)->state);
	}
	printk(KERN_INFO "wait_queue_num :%d\n",
			wait_queue_num);

	return 0;
}

static void __exit add_wait_queue_exclusive_exit(void)
{
	printk(KERN_INFO "add_wait_queue_exclusive_exit\n");
}

module_init(add_wait_queue_exclusive_init);
module_exit(add_wait_queue_exclusive_exit);

MODULE_LICENSE("GPL");
