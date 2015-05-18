#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	wait_queue_head_t head;
	wait_queue_t data;
	long remaintime;
	struct completion *complet = arg;
	int ret = -1;

	init_waitqueue_head(&head);
	init_waitqueue_entry(&data, current);
	add_wait_queue(&head, &data);
	remaintime = sleep_on_timeout(&head, 10);
#define COMPLETE_BEFOR_TEST	0
#if (COMPLETE_BEFOR_TEST == 1)
	complete(complet);
	printk(KERN_INFO "done :%d\n", complet->done);
#endif
	ret = completion_done(complet);
	printk(KERN_INFO "completion_done result :%d\n", ret);
	printk(KERN_INFO "parent pid :%d, child pid :%d in child\n",
			current->real_parent->pid,
			current->pid);
#if (COMPLETE_BEFOR_TEST == 0)
	complete(complet);
	printk(KERN_INFO "done :%d\n", complet->done);
#endif

	return 0;
}
static int completion_done_init(void)
{
	pid_t pid;
	struct pid *kpid;
	struct task_struct *task;
	struct completion complet;
	wait_queue_t data;
	printk(KERN_INFO "completion_done_init\n");
	pid = kernel_thread(myfunc, &complet, CLONE_KERNEL);
	kpid = find_get_pid(pid);
	task = pid_task(kpid, PIDTYPE_PID);
	init_completion(&complet);
	init_waitqueue_entry(&data, task);
	__add_wait_queue_tail(&complet.wait, &data);
	wait_for_completion(&complet);
	printk(KERN_INFO "parent pid %d ,child pid :%d in parent\n",
			current->pid, pid);
	return 0;
}

static void completion_done_exit(void)
{
	printk(KERN_INFO "completion_done_exit\n");
}

module_init(completion_done_init);
module_exit(completion_done_exit);

MODULE_LICENSE("GPL");
