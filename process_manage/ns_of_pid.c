#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	printk(KERN_INFO "child pid :%d\n",
			current->pid);
	return 0;
}

struct pid_namespace *my_ns= NULL;

static int __init ns_of_pid_init(void)
{
	pid_t pid		= -1;
	struct pid *kpid	= NULL;
	printk(KERN_INFO "ns_of_pid_init\n");
	/* create thread */
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	if (0 > pid) {
		printk(KERN_INFO "kernel_thread error \n");
		goto finish;
	}
	/* find pid */
#if 0
struct pid *find_vpid(int nr)
#endif
	kpid = find_vpid(pid);
	if (NULL == kpid) {
		printk(KERN_INFO "find_vpid error\n");
		goto finish;
	}
	/* get namespace infomation */
#if 0
static inline struct pid_namespace *ns_of_pid(struct pid *pid)
#endif
	my_ns = ns_of_pid(kpid);
	if (NULL == my_ns) {
		printk(KERN_INFO "ns_of_pid error\n");
		goto finish;
	}
	printk(KERN_INFO "parent pid :%d\n",
			current->pid);	
	printk(KERN_INFO "kpid->level: %d\n",
			kpid->level);
#if 0
	printk(KERN_INFO "last_pid :%d\n",
			my_ns->last_pid);
	printk(KERN_INFO "my_ns->level :%d, kpid->level :%d\n",
			my_ns->level, kpid->level);
#endif
finish:
	return 0;
}

static void __exit ns_of_pid_exit(void)
{
	printk(KERN_INFO "ns_of_pid_exit\n");
}

module_init(ns_of_pid_init);
module_exit(ns_of_pid_exit);

MODULE_LICENSE("GPL");
