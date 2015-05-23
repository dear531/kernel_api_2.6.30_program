#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	printk(KERN_INFO "child pid :%d, current->static_prio :%d\n",
			current->pid, current->static_prio);
	printk(KERN_INFO "child pid nice :%d\n", task_nice(current));
	return 0;
}

static int __init set_user_nice_init(void)
{
	pid_t pid;
	struct pid *kpid;
	struct task_struct *task;
	printk(KERN_INFO "set_user_nice_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
#if 0
struct pid *find_get_pid(pid_t nr)
#endif
	kpid = find_get_pid(pid);
#if 0
enum pid_type
{
	PIDTYPE_PID,
	PIDTYPE_PGID,
	PIDTYPE_SID,
	PIDTYPE_MAX
};
struct task_struct *pid_task(struct pid *pid, enum pid_type type)
#endif
	task = pid_task(kpid, PIDTYPE_PID);
#if 0
void set_user_nice(struct task_struct *p, long nice)
	int prio, static_prio, normal_prio;
#endif
	printk(KERN_INFO "befor set_user_nice child pid :%d, static_prio :%d, prio :%d, normal_prio :%d\n",
			task->pid, task->static_prio, task->prio, task->normal_prio);

	set_user_nice(task, 19);

	printk(KERN_INFO "after set_user_nice child pid :%d, static_prio :%d, prio :%d, normal_prio :%d\n",
			task->pid, task->static_prio, task->prio, task->normal_prio);

	return 0;
}

static void __exit set_user_nice_exit(void)
{
	printk(KERN_INFO "set_user_nice_exit\n");
}

module_init(set_user_nice_init);
module_exit(set_user_nice_exit);

MODULE_LICENSE("GPL");
