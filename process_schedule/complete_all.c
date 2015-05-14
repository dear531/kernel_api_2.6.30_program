#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	printk(KERN_INFO "child pid :%d parent pid :%d in child\n",
			current->pid, current->real_parent->pid);
	printk(KERN_INFO "befor complete_all child state :%ld parent state :%ld in parent\n",
			current->state, current->real_parent->state);
	printk(KERN_INFO "wait.done :%d\n",
			((struct completion *)arg)->done);
	complete_all((struct completion *)arg);
	printk(KERN_INFO "after complete_all child state :%ld parent state :%ld in parent\n",
			current->state, current->real_parent->state);
	printk(KERN_INFO "wait.done :%d\n",
			((struct completion *)arg)->done);
	return 0;
}
static int __init complete_all_init(void)
{
	struct completion	comple;
	wait_queue_t		data;
	pid_t			pid;
	long			remaintime;
	printk(KERN_INFO "complete_all_init\n");
	init_completion(&comple);
	init_waitqueue_head(&comple.wait);
	init_waitqueue_entry(&data, current);
	printk(KERN_INFO "current->flags :%x\n", current->flags);
	printk(KERN_INFO "WQ_FLAG_EXCLUSIVE:%x\n", WQ_FLAG_EXCLUSIVE);
	add_wait_queue(&comple.wait, &data);
	pid = kernel_thread(myfunc, &comple, CLONE_KERNEL);
	remaintime = sleep_on_timeout(&comple.wait, 100);
	printk(KERN_INFO "remaintime :%ld\n", remaintime);
	return 0;
}

static void __exit complete_all_exit(void)
{
	printk(KERN_INFO "complete_all_exit\n");
}

module_init(complete_all_init);
module_exit(complete_all_exit);

MODULE_LICENSE("GPL");
