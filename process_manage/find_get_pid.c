#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	return 0;
}

static int __init find_get_pid_init(void)
{
	int pret;
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
	struct pid *kpid;
	printk(KERN_INFO "find_get_pid_init\n");
	pret = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	if (0 < pret && NULL != (kpid = find_get_pid(pret))) {
		printk(KERN_INFO "count :%d\n", kpid->count);
		printk(KERN_INFO "level :%d\n", kpid->level);
		printk(KERN_INFO "pid :%d\n",kpid->numbers[kpid->level].nr);
		printk(KERN_INFO "pret :%d\n", pret);
	}
	return 0;
}

static void __exit find_get_pid_exit(void)
{
	printk(KERN_INFO "find_get_pid_exit\n");
}

module_init(find_get_pid_init);
module_exit(find_get_pid_exit);

MODULE_LICENSE("GPL");
