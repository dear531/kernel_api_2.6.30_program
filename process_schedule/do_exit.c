#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	printk(KERN_INFO "always appaer\n");
#if 0
	do_exit(0);
#endif
	printk(KERN_INFO "not do_exit appear in myfunc\n");
	return 0;
}

static int __init do_exit_init(void)
{
	pid_t pid;
	printk(KERN_INFO "do_exit_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	return 0;
}

static void __exit do_exit_exit(void)
{
	printk(KERN_INFO "do_exit_exit\n");
}

module_init(do_exit_init);
module_exit(do_exit_exit);

MODULE_LICENSE("GPL");
