#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>
#if 0
struct pid *find_get_pid(pid_t nr)
find_get_pid();
struct pid *find_vpid(int nr)
find_vpid();
#endif

static int myfunc(void *arg)
{
	return 0;
}

static int __init find_vpid_init(void)
{
	pid_t pid;
	struct pid *kpid, *kpid2;
	struct task_struct *task, *task2;
	printk(KERN_INFO "find_vpid_init\n");
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
struct task_struct *find_task_by_pid_ns(pid_t nr, struct pid_namespace *ns)
#endif
	task = find_task_by_pid_ns(kpid->numbers[kpid->level].nr,
			kpid->numbers[kpid->level].ns);
	if (NULL == task) {
		printk(KERN_INFO "find_task_by_pid_ns error\n");
		goto finish;
	}
	printk(KERN_INFO "kpid->count :%d\n", kpid->count);
	printk(KERN_INFO "kpid->numbers[kpid->level].nr :%d\n",
			kpid->numbers[kpid->level].nr);
	printk(KERN_INFO "task->pid :%d, task->tgid :%d\n",
			task->pid, task->tgid);
	printk(KERN_INFO "pid :%d\n", pid);
	kpid2 = find_get_pid(pid);
	if (NULL == kpid2) {
		printk(KERN_INFO "find_get_pid error\n");
		goto finish;
	}
	printk(KERN_INFO "kpid2->count :%d\n", kpid2->count);

	kpid2 = find_get_pid(pid);
	if (NULL == kpid2) {
		printk(KERN_INFO "find_get_pid error\n");
		goto finish;
	}
	printk(KERN_INFO "kpid2->count :%d\n", kpid2->count);

	/* compare kpid2 of find_get_pid and kpid of find_vpid */
	printk(KERN_INFO "kpid :%p, kpid2: %p\n", kpid, kpid2);
finish:
	return 0;
}

static void __exit find_vpid_exit(void)
{
	printk(KERN_INFO "find_vpid_exit\n");
}

module_init(find_vpid_init);
module_exit(find_vpid_exit);

MODULE_LICENSE("GPL");
