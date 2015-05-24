#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	printk(KERN_INFO "into %s\n", __func__);
	printk(KERN_INFO "befor wake_up_process parent state :%ld in child\n",
			current->real_parent->state);
	wake_up_process(current->real_parent);
	printk(KERN_INFO "after wake_up_process parent state :%ld in child\n",
			current->real_parent->state);
	printk(KERN_INFO "out %s\n", __func__);
	return 0;
}

static int __init wake_up_process_init(void)
{
	pid_t pid;
	long t;
	wait_queue_head_t head;
	wait_queue_t data;
	printk(KERN_INFO "wake_up_process_init\n");
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	init_waitqueue_head(&head);
	init_waitqueue_entry(&data, current);
	add_wait_queue(&head, &data);
	t = sleep_on_timeout(&head, 100);
	printk(KERN_INFO "sleep_on_timeout remain time :%ld\n", t);

	return 0;
}

static void __exit wake_up_process_exit(void)
{
	printk(KERN_INFO "wake_up_process_exit\n");
}

module_init(wake_up_process_init);
module_exit(wake_up_process_exit);

MODULE_LICENSE("GPL");
