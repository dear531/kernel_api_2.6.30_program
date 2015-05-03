#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	return 0;
}
static int __init find_task_by_pid_type_ns_init(void)
{
	pid_t pid;
	struct pid *kpid;
	struct task_struct *task;
	printk(KERN_INFO "find_task_by_pid_type_ns\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	if (0 > pid) {
		printk(KERN_INFO "kernel_thread error\n");
		goto finish;
	}
#if 0
struct pid *find_get_pid(pid_t nr)
#endif
	kpid = find_get_pid(pid);
	if (NULL == kpid) {
		printk(KERN_INFO "find_get_pid error\n");
		goto finish;
	}
#if 0
enum pid_type
{
	PIDTYPE_PID,
	PIDTYPE_PGID,
	PIDTYPE_SID,
	PIDTYPE_MAX
};
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
struct task_struct *find_task_by_pid_type_ns(int type, int nr,
		struct pid_namespace *ns)
#endif
	task = find_task_by_pid_type_ns(PIDTYPE_PID,
			kpid->numbers[kpid->level].nr, kpid->numbers[kpid->level].ns);
	if (NULL == task) {
		printk(KERN_INFO "find_task_by_pid_type_ns error\n");
		goto finish;
	}
	printk(KERN_INFO "pid :%d, kpid->number[level].nr :%d ,task->pid :%d\n",
			pid, kpid->numbers[kpid->level].nr, task->pid);
	printk(KERN_INFO "task->tgid :%d\n",
			task->tgid);
finish:
	return 0;
}

static void __exit find_task_by_pid_type_ns_exit(void)
{
	printk(KERN_INFO "find_task_by_pid_type_ns\n");
}

module_init(find_task_by_pid_type_ns_init);
module_exit(find_task_by_pid_type_ns_exit);

MODULE_LICENSE("GPL");
