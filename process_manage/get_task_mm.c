#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	return 0;
}

static int __init get_task_mm_init(void)
{
	pid_t pid;
	struct pid *kpid;
	struct task_struct *task;
	struct mm_struct *mm_task;
	printk(KERN_INFO "get_task_mm_init\n");
	/* create kernel thread */
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	if (0 > pid) {
		printk(KERN_INFO "kernel_thread error\n");
		goto finish;
	}
	/* get pid info */
#if 0
struct pid *find_vpid(int nr)
#endif
	kpid = find_vpid(pid);
	if (NULL == kpid) {
		printk(KERN_INFO "find_vpid error \n");
		goto finish;
	}
	/* get task info */
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
	task = find_task_by_pid_type_ns(PIDTYPE_PID, kpid->numbers[kpid->level].nr,
			kpid->numbers[kpid->level].ns);
	if (NULL == task) {
		printk(KERN_INFO "find_task_pid_type_ns error \n");
		goto finish;
	}
	
	/* get memory info */
#if 0
struct mm_struct *get_task_mm(struct task_struct *task)
#endif
	mm_task = get_task_mm(task);
	if(NULL == mm_task) {
		printk(KERN_INFO "get_task_mm error\n");
		goto finish;
	}
	printk(KERN_INFO "mm_users:%d, mm_count:%d\n",
			mm_task->mm_users, mm_task->mm_count);
#ifdef CONFIG_MM_OWNER
	printk(KERN_INFO "owner->pid :%d, owner->tgid :%d\n",
			mm_task->owner->pid, mm_task->owner->tgid);
#endif
	printk(KERN_INFO "current->pid :%d\n",
			current->pid);
	printk(KERN_INFO "pid :%d\n", pid);
finish:
	return 0;
}

static void __exit get_task_mm_exit(void)
{
	printk(KERN_INFO "get_task_mm_exit\n");
}

module_init(get_task_mm_init);
module_exit(get_task_mm_exit);

MODULE_LICENSE("GPL");
