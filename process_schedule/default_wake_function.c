#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

wait_queue_t data;
static int myfunc(void *arg)
{
	int ret;
	printk(KERN_INFO "befor default_wake_function parent state :%ld\n",
			current->real_parent->state);
	if (NULL != data.private)
		ret = default_wake_function(&data, TASK_NORMAL, 0, NULL);
	printk(KERN_INFO "ret :%d\n", ret);
	printk(KERN_INFO "after default_wake_function parent state :%ld\n",
			current->real_parent->state);
	return 0;
}

static int __init default_wake_function_init(void)
{
	pid_t pid;
	wait_queue_head_t head;
	long remaintime;
	int ret = -1;
	printk(KERN_INFO "default_wake_function_init\n");
	init_waitqueue_head(&head);
	init_waitqueue_entry(&data, current);
	add_wait_queue(&head, &data);
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	remaintime = sleep_on_timeout(&head, 10);
	printk(KERN_INFO "remaintime :%ld\n", remaintime);
#if 0
int default_wake_function(wait_queue_t *curr, unsigned mode, int sync,
			  void *key)
#endif
	if (NULL != data.private)
		ret = default_wake_function(&data, TASK_NORMAL, 0, NULL);
	printk(KERN_INFO "parent defaulte_wake_funcition result %d\n",
			ret);
	return 0;
}

static void __exit default_wake_function_exit(void)
{
	printk(KERN_INFO "default_wake_function_exit\n");
}

module_init(default_wake_function_init);
module_exit(default_wake_function_exit);

MODULE_LICENSE("GPL");
