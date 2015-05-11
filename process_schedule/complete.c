#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
#if 0
struct completion {
	unsigned int done;
	wait_queue_head_t wait;
};
void complete(struct completion *x)
#endif
	printk(KERN_INFO "child pid :%d, parent pid :%d in child\n",
			current->pid, current->real_parent->pid);
	printk(KERN_INFO "befor complet parent state :%ld in child\n",
			current->real_parent->state);
	complete((struct completion *)arg);
	printk(KERN_INFO "after complet parent state :%ld in child\n",
			current->real_parent->state);
	return 0;
}

static int __init complete_init(void)
{
	pid_t pid;
	struct completion	comple;
	wait_queue_t		data;
	long			remaintime;
	printk(KERN_INFO "complete_init\n");
	init_completion(&comple);
	init_waitqueue_entry(&data, current);
	add_wait_queue(&comple.wait, &data);

	printk(KERN_INFO "after wake up parent state :%ld\n",
			current->state);

	pid = kernel_thread(myfunc, &comple, CLONE_KERNEL);
	
	printk(KERN_INFO "child pid :%d, parent pid :%d in parent\n",
			pid, current->pid);

	remaintime = sleep_on_timeout(&comple.wait, 100);
	printk(KERN_INFO "remaintime :%ld\n", remaintime);
	printk(KERN_INFO "comple.done :%d\n", comple.done);

	printk(KERN_INFO "after wake up parent state :%ld\n",
			current->state);

	return 0;
}

static void __exit complete_exit(void)
{
	printk(KERN_INFO "complete_exit\n");
}

module_init(complete_init);
module_exit(complete_exit);

MODULE_LICENSE("GPL");
