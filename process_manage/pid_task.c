#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	return 0;
}

static int pid_task_init(void)
{
	pid_t pid;
	struct pid *kpid;
	struct task_struct *task1, *task2, *task3;
	printk(KERN_INFO "pid_task_init\n");
	/* create thread */
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	if (0 > pid) {
		printk(KERN_INFO "kernel_thread error\n");
		goto finish;
	}
	/* find pid */
#if 0
struct pid *find_vpid(int nr)
#endif
	kpid = find_vpid(pid);
	if (NULL == kpid) {
		printk(KERN_INFO "find_vpid error\n");
		goto finish;
	}
#if 0
struct task_struct *find_task_by_pid_ns(pid_t nr, struct pid_namespace *ns)
struct task_struct *find_task_by_pid_type_ns(int type, int nr,
		struct pid_namespace *ns)
enum pid_type
{
	PIDTYPE_PID,
	PIDTYPE_PGID,
	PIDTYPE_SID,
	PIDTYPE_MAX
};
struct task_struct *pid_task(struct pid *pid, enum pid_type type)
#endif
	task1 = find_task_by_pid_ns(kpid->numbers[kpid->level].nr,
			kpid->numbers[kpid->level].ns);
	task2 = find_task_by_pid_type_ns(PIDTYPE_PID, kpid->numbers[kpid->level].nr,
			kpid->numbers[kpid->level].ns);
	task3 = pid_task(kpid, PIDTYPE_PID);
	printk(KERN_INFO "task1 %p, task2 %p, task3 :%p\n",
			task1, task2, task3);
finish:
	return 0;
}

static void pid_task_exit(void)
{
	printk(KERN_INFO "pid_task_exit\n");
}

module_init(pid_task_init);
module_exit(pid_task_exit);

MODULE_LICENSE("GPL");
