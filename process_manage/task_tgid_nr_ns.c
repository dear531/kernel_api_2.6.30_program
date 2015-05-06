#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	return 0;
}

static int __init task_tgid_nr_ns_init(void)
{
	pid_t pid, pid2;
	struct pid *kpid;
	struct task_struct *task;
	printk(KERN_INFO "task_tgid_nr_ns_init\n");
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
		printk(KERN_INFO "find_vpid error \n");
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
struct task_struct *find_task_by_pid_type_ns(int type, int nr,
		struct pid_namespace *ns)
#endif
	task = find_task_by_pid_type_ns(PIDTYPE_PID,
			kpid->numbers[kpid->level].nr, kpid->numbers[kpid->level].ns);
#if 0
pid_t task_tgid_nr_ns(struct task_struct *tsk, struct pid_namespace *ns)
#endif
	pid2 = task_tgid_nr_ns(task, kpid->numbers[kpid->level].ns);
	if (0 >= pid2) {
		printk(KERN_INFO "task_tgid_nr_ns\n");
		goto finish;
	}
	printk(KERN_INFO "pid :%d, pid2 :%d\n",
			pid, pid2);
finish:
	return 0;
}

static void __exit task_tgid_nr_ns_exit(void)
{
	printk(KERN_INFO "task_tgid_nr_ns_exit\n");
}

module_init(task_tgid_nr_ns_init);
module_exit(task_tgid_nr_ns_exit);

MODULE_LICENSE("GPL");
