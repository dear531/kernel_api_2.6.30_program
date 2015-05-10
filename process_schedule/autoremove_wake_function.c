#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

wait_queue_head_t	head;
wait_queue_t 		data;
static int myfunc(void *arg)
{
	wait_queue_t	*curr,	*next;
	int		wait_queue_num = 0;
	int		wake_return;
	list_for_each_entry_safe(curr, next, &head.task_list, task_list) {
		wait_queue_num++;
		printk(KERN_INFO "curr->private->pid :%d\n",
				((struct task_struct *)curr->private)->pid);
		printk(KERN_INFO "curr->private->state :%ld\n",
				((struct task_struct *)curr->private)->state);
		
	}
	printk(KERN_INFO "wait_queue_num :%d\n",
			wait_queue_num);
	/* return 1 success, return 0 failure */
	wake_return = autoremove_wake_function(&data, TASK_NORMAL, 0, NULL);
	printk(KERN_INFO "wake_return :%d\n",
			wake_return);
	wait_queue_num = 0;
	list_for_each_entry_safe(curr, next, &head.task_list, task_list) {
		wait_queue_num++;
		printk(KERN_INFO "curr->private->pid :%d\n",
				((struct task_struct *)curr->private)->pid);
		printk(KERN_INFO "curr->private->state :%ld\n",
				((struct task_struct *)curr->private)->state);
		
	}
	printk(KERN_INFO "wait_queue_num :%d\n",
			wait_queue_num);
	return 0;
}
static int __init autoremove_wake_function_init(void)
{
	pid_t pid;
	long			time;
	int 			wait_queue_num;
	wait_queue_t 		*curr, *next;
	printk(KERN_INFO "autoremove_wake_function_init\n");

	init_waitqueue_head(&head);
	init_waitqueue_entry(&data, current);
	add_wait_queue(&head, &data);

	time = sleep_on_timeout(&head, 1000);
	printk(KERN_INFO "time :%ld\n", time);

	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);

	time = sleep_on_timeout(&head, 1000);
	printk(KERN_INFO "time :%ld\n", time);

	if (NULL != data.private) {
		autoremove_wake_function(&data, TASK_NORMAL, 0, NULL);
		printk(KERN_INFO "autoremove_wake_function\n");
	}

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
		printk(KERN_INFO "curr->private->pid :%d\n",
				((struct task_struct *)curr->private)->pid);
		printk(KERN_INFO "curr->private->state :%ld\n",
				((struct task_struct *)curr->private)->state);
	}
	printk(KERN_INFO "wait_queue_num :%d\n",
			wait_queue_num);

	return 0;
}

static void __exit autoremove_wake_function_exit(void)
{
	printk(KERN_INFO "autoremove_wake_function_exit\n");
}

module_init(autoremove_wake_function_init);
module_exit(autoremove_wake_function_exit);

MODULE_LICENSE("GPL");
