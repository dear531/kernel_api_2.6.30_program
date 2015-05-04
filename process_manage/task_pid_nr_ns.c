#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/pid.h>
static int myfunction(void *arg)
{
	return 0;
}
static int __init task_pid_nr_ns_init(void)
{
	int result;
	struct pid *kpid;
	struct task_struct *task;
	pid_t result1;
	printk(KERN_INFO "task_pid_nr_ns_init\n");
	result = kernel_thread(myfunction, NULL, CLONE_KERNEL);
	kpid = find_get_pid(result);
	task = pid_task(kpid, PIDTYPE_PID);
	result1 = __task_pid_nr_ns(task, PIDTYPE_PID, kpid->numbers[kpid->level].ns);
	printk(KERN_INFO "the result of the kernel_thread is :%d\n",
			result);
	printk(KERN_INFO "current thread pid current->pid :%d\n", current->pid);
	printk(KERN_INFO "get_pid_result : %d\n",
			kpid->numbers[kpid->level].nr);
	printk(KERN_INFO "__task_pid_nr_ns result :%d\n",
			result1);
	return 0;
}

static void __exit task_pid_nr_ns_exit(void)
{
	printk(KERN_INFO "task_pid_nr_ns_exit\n");
}

module_init(task_pid_nr_ns_init);
module_exit(task_pid_nr_ns_exit);

MODULE_LICENSE("GPL");
