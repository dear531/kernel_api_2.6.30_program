#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/pid.h>

static int myfunc(void *arg)
{
	return 0;
}

static int __init add_wait_queue_init(void)
{
	wait_queue_head_t	head;
	pid_t			pid1,	pid2;
	struct pid		*kpid1,	*kpid2;
	struct task_struct 	*task1,	*task2;
	wait_queue_t		data1,	data2, *curr, *next;
	int wait_queue_num;
	printk(KERN_INFO "add_wait_queue_init\n");

	pid1 = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	pid2 = kernel_thread(myfunc, NULL, CLONE_KERNEL);

	printk(KERN_INFO "pid1 :%d, pid2 :%d\n",
			pid1, pid2);
	kpid1 = find_get_pid(pid1);
	kpid2 = find_get_pid(pid2);

	task1 = pid_task(kpid1, PIDTYPE_PID);
	task2 = pid_task(kpid2, PIDTYPE_PID);

	init_waitqueue_head(&head);
	init_waitqueue_entry(&data1, task1);
	INIT_LIST_HEAD(&data1.task_list);
	init_waitqueue_entry(&data2, task2);
	INIT_LIST_HEAD(&data2.task_list);

	add_wait_queue(&head, &data1);
	add_wait_queue(&head, &data2);

	wait_queue_num = 0;
	list_for_each_entry_safe(curr, next, &head.task_list, task_list) {
		wait_queue_num++;
		printk(KERN_INFO "curr->pid %d\n",
				((struct task_struct *)curr->private)->pid);
		printk(KERN_INFO "curr->state %ld\n",
				((struct task_struct *)curr->private)->state);
	}
	printk(KERN_INFO "wait_queue_num :%d\n",
			wait_queue_num);

	return 0;
}

static void __exit add_wait_queue_exit(void)
{
	printk(KERN_INFO "add_wait_queue_exit\n");
}

module_init(add_wait_queue_init);
module_exit(add_wait_queue_exit);

MODULE_LICENSE("GPL");
