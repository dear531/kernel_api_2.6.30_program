#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	return 0;
}

static int __init is_container_init_init(void)
{
	pid_t pid;
	struct pid *kpid;
	struct task_struct *task;
	printk(KERN_INFO "is_container_init_init\n");
	/* create thread */
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	if (0 > pid) {
		printk(KERN_INFO "kernel_thread error \n");
		goto finish;
	}
	/* get pid */
#if 0
struct pid *find_vpid(int nr)
#endif
	kpid = find_vpid(pid);
	if (NULL == kpid) {
		printk(KERN_INFO "find_vpid error \n");
		goto finish;
	}
	/* get task */
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
	/* is or not init */
#if 0
int is_container_init(struct task_struct *tsk)
#endif
	printk(KERN_INFO "pid :%d\n", pid);
	if (1 == is_container_init(task)) {
		printk(KERN_INFO "pid is 1\n");
	} else {
		printk(KERN_INFO "pid is not 1\n");
	}
finish:
	return 0;
}

static void __exit is_container_init_exit(void)
{
	printk(KERN_INFO "is_container_init_exit\n");
}

module_init(is_container_init_init);
module_exit(is_container_init_exit);

MODULE_LICENSE("GPL");
