#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	printk(KERN_INFO "child pid :%d\n",
			current->pid);
	printk(KERN_INFO "child policy :%d, child priority :%d\n",
			current->policy, current->rt_priority);
	return 0;
}
static int __init sched_setscheduler_init(void)
{
	pid_t pid;
	struct pid *kpid;
	struct task_struct *task;
	struct sched_param param;
	int ret;
	printk(KERN_INFO "sched_setscheduler_init\n");
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
struct sched_param {
	int sched_priority;
};
int sched_setscheduler(struct task_struct *p, int policy,
		       struct sched_param *param)
#endif
	param.sched_priority = 1;
	ret = sched_setscheduler(task, SCHED_FIFO, &param);
	printk(KERN_INFO "result of shced_setscheduler is %d\n", ret);
	return 0;
}

static void __exit sched_setscheduler_exit(void)
{
	printk(KERN_INFO "sched_setscheduler_exit\n");
}

module_init(sched_setscheduler_init);
module_exit(sched_setscheduler_exit);

MODULE_LICENSE("GPL");
