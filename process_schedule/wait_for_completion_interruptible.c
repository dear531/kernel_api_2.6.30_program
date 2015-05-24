#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

struct completion comple;

static int myfunc(void *arg)
{
	long t;
	wait_queue_head_t head;
	wait_queue_t data;
	init_waitqueue_head(&head);
	init_waitqueue_entry(&data, current);
	add_wait_queue(&head, &data);
	t = sleep_on_timeout(&head, 1000);
	complete(&comple);
	printk(KERN_INFO "remain time t :%ld\n", t);
	return 0;
}

static int __init wait_for_completion_interruptible_init(void)
{
	pid_t pid;
	struct pid *kpid;
	struct task_struct *task;
	wait_queue_t data;
	int t;
	printk(KERN_INFO "wait_for_completion_interruptible_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
#if 0
struct pid *find_get_pid(pid_t nr)
#endif
	kpid = find_get_pid(pid);
#if 0
struct task_struct *pid_task(struct pid *pid, enum pid_type type)
#endif
	task = pid_task(kpid, PIDTYPE_PID);
#if 0
static inline void init_completion(struct completion *x)
#endif
	init_completion(&comple);
#if 0
static inline void init_waitqueue_entry(wait_queue_t *q, struct task_struct *p)
#endif
	init_waitqueue_entry(&data, task);
#if 0
static inline void __add_wait_queue_tail(wait_queue_head_t *head,
						wait_queue_t *new)
#endif
	__add_wait_queue_tail(&comple.wait, &data);
#if 0
int __sched wait_for_completion_interruptible(struct completion *x)
#endif
	printk(KERN_INFO "befor wait_for_competion comple.done :%d\n",
			comple.done);
	t = wait_for_completion_interruptible(&comple);
	printk(KERN_INFO "wait_for_completion_interruptible result :%d\n", t);
	printk(KERN_INFO "after wait_for_competion comple.done :%d\n",
			comple.done);

	return 0;
}

static void __exit wait_for_completion_interruptible_exit(void)
{
	printk(KERN_INFO "wait_for_completion_interruptible_exit\n");
}

module_init(wait_for_completion_interruptible_init);
module_exit(wait_for_completion_interruptible_exit);

MODULE_LICENSE("GPL");
