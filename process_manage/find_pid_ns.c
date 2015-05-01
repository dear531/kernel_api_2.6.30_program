#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/pid.h>

static int myfunc(void *arg)
{
	return 0;
}
static int __init find_pid_ns_init(void)
{
	int ret;
	struct pid *kpid, *fpid;
	printk(KERN_INFO "find_pid_ns_init\n");
#if 0
struct pid *find_pid_ns(int nr, struct pid_namespace *ns)
int kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
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

extern struct pid init_struct_pid;
struct pid *find_pid_ns(int nr, struct pid_namespace *ns)
#endif
	ret = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	if (NULL != (kpid = find_get_pid(ret)) 
		&& NULL != (fpid = find_pid_ns(kpid->numbers[kpid->level].nr,
				kpid->numbers[kpid->level].ns))) {
		printk(KERN_INFO "kpid :%p, fpid :%p\n", kpid, fpid);
		printk(KERN_INFO "count :%d\n", kpid->count);
	}
	return 0;
}

static void __exit find_pid_ns_exit(void)
{
	printk(KERN_INFO "find_pid_ns_exit\n");
}

module_init(find_pid_ns_init);
module_exit(find_pid_ns_exit);

MODULE_LICENSE("GPL");
