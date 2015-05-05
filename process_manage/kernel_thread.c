#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	int *tmp = arg;
	printk(KERN_INFO "child pid :%d in child\n",
			current->pid);
	printk(KERN_INFO "tmp value :%x, tmp address %p in child\n",
			*tmp, tmp);
	return 0;
}

static int __init kernel_thread_init(void)
{
	pid_t pid;
	int tmp = 0x0f;
	printk(KERN_INFO "kernel_thread_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, &tmp, CLONE_KERNEL);
	if (0 > pid) {
		printk(KERN_INFO "kernel_thread error \n");
		goto finish;
	}
	printk(KERN_INFO "show child pid :%d in parent\n", pid);
	printk(KERN_INFO "show parent pid :%d in parent\n",
			current->pid);
	printk(KERN_INFO "tmp value :%x, address :%p in parent\n",
			tmp, &tmp);
finish:
	return 0;
}

static void __exit kernel_thread_exit(void)
{
	printk(KERN_INFO "kernel_thread_exit\n");
}

module_init(kernel_thread_init);
module_exit(kernel_thread_exit);

MODULE_LICENSE("GPL");
