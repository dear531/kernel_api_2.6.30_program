#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	return 0;
}

static int __init pid_vnr_init(void)
{
	pid_t pid1, pid2;
	struct pid *kpid;
	printk(KERN_INFO "pid_vnr_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid1 = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	if (0 > pid1) {
		printk(KERN_INFO "kernel_thread error \n");
		goto finish;
	}
#if 0
struct pid *find_vpid(int nr)
#endif
	kpid = find_vpid(pid1);
	if (NULL == kpid) {
		printk(KERN_INFO "find_vpid error \n");
		goto finish;
	}
#if 0
pid_t pid_vnr(struct pid *pid)
#endif
	pid2 = pid_vnr(kpid);
	if (0 >= pid2) {
		printk(KERN_INFO "pid_vnr error\n");
		goto finish;
	}
	printk(KERN_INFO "pid1 :%d, pid2 :%d\n",
			pid1, pid2);
finish:
	return 0;
}

static void __exit pid_vnr_exit(void)
{
	printk(KERN_INFO "pid_vnr_exit\n");
}

module_init(pid_vnr_init);
module_exit(pid_vnr_exit);

MODULE_LICENSE("GPL");
