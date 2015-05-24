#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

static int myfunc(void *arg) 
{
	printk(KERN_INFO "current->real_parent->state :%ld in child \n",
			current->real_parent->state);
	return 0;
}

static int __init yield_init(void)
{
	printk(KERN_INFO "yield_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	kernel_thread(myfunc, NULL, CLONE_KERNEL);
	yield();
	printk(KERN_INFO "yield_init end\n");
	return 0;
}

static void __exit yield_exit(void)
{
	printk(KERN_INFO "yield_exit\n");
}

module_init(yield_init);
module_exit(yield_exit);

MODULE_LICENSE("GPL");
