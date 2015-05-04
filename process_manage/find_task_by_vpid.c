#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	return 0;
}

static int __init find_task_by_vpid_init(void)
{
	pid_t childpid;
	struct pid *kpid;
	struct task_struct *task;
	printk(KERN_INFO "find_task_by_vpid_init\n");
#if 0
struct task_struct *find_task_by_vpid(pid_t vnr)
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
struct pid *find_get_pid(pid_t nr)
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
	childpid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	kpid = find_get_pid(childpid);
	if (NULL == kpid) {
		printk(KERN_INFO "find_get_pid error\n");
		goto finish;
	}
	task = find_task_by_vpid(pid_vnr(kpid));
	if (NULL == task) {
		printk(KERN_INFO "find_task_by_vpid\n");
		goto finish;
	}
	printk(KERN_INFO "kernel_thread pid :%d\n", childpid);
	printk(KERN_INFO "kpid->numbers[level].nr :%d\n", kpid->numbers[kpid->level].nr);
	printk(KERN_INFO "task->pid :%d, task->tgid :%d\n", task->pid, task->tgid);
	printk(KERN_INFO "current->pid :%d\n", current->pid);
finish:
	return 0;
}

static void __exit find_task_by_vpid_exit(void)
{
	printk(KERN_INFO "find_task_by_vpid_exit\n");
}

module_init(find_task_by_vpid_init);
module_exit(find_task_by_vpid_exit);

MODULE_LICENSE("GPL");
