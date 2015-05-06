#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	return 0;
}

static int __init task_active_pid_ns_init(void)
{
	pid_t pid;
	struct pid *kpid;
	struct task_struct *task;
	struct pid_namespace *ns;
	printk(KERN_INFO "task_active_pid_ns_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	if (0 >= pid) {
		printk(KERN_INFO "kernel_thread error \n");
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
struct task_struct *pid_task(struct pid *pid, enum pid_type type)
#endif
	task = pid_task(kpid, PIDTYPE_PID);
	if (NULL == task) {
		printk(KERN_INFO "pid_task error\n");
		goto finish;
	}
#if 0
struct pid_namespace *task_active_pid_ns(struct task_struct *tsk)
	ns = task_active_pid_ns(task);
#endif
	ns = ns_of_pid(task_pid(task));
	if (NULL == task) {
		printk(KERN_INFO "task_active_pid_ns error\n");
		goto finish;
	}
	printk(KERN_INFO "ns :%p, task->numbers[%d].ns:%p\n",
			ns, kpid->level, kpid->numbers[kpid->level].ns);
finish:
	return 0;
}

static void __exit task_active_pid_ns_exit(void)
{
	printk(KERN_INFO "task_active_pid_ns_exit\n");
}

module_init(task_active_pid_ns_init);
module_exit(task_active_pid_ns_exit);

MODULE_LICENSE("GPL");
