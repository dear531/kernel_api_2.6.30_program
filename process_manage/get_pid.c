#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	return 0;
}

static int __init get_pid_init(void)
{
	pid_t pid;
	struct pid *kpid;
	printk(KERN_INFO "get_pid_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	if (0 > pid) {
		printk(KERN_INFO "kernel_thread error\n");
		goto finish;
	}
#if 0
struct pid *find_vpid(int nr)
#endif
	kpid = find_vpid(pid);
	if (NULL == kpid) {
		printk(KERN_INFO "find_vpid error\n");
		goto finish;
	}
#if 0
struct upid {
	/* Try to keep pid_chain in the same cacheline as nr for find_vpid */
	int nr;
	struct pid_namespace *ns;
	struct hlist_node pid_chain;
};

struct pid
{
	atomic_t count;
	unsigned int level;
	/* lists of tasks that use this pid */
	struct hlist_head tasks[PIDTYPE_MAX];
	struct rcu_head rcu;
	struct upid numbers[1];
};
#endif
	printk(KERN_INFO "befor get_pid kpid->count :%d\n",
			kpid->count);
	printk(KERN_INFO "kpid address :%p\n", kpid);
	kpid = get_pid(kpid);
	printk(KERN_INFO "after get_pid kpid->count :%d\n",
			kpid->count);
	printk(KERN_INFO "kpid address :%p\n", kpid);
finish:
	return 0;
}

static void __exit get_pid_exit(void)
{
	printk(KERN_INFO "get_pid_exit\n");
}

module_init(get_pid_init);
module_exit(get_pid_exit);

MODULE_LICENSE("GPL");
