#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

struct completion comple;

static int myfunc(void *arg)
{
	wait_queue_head_t head;
	wait_queue_t data;
	long t;
	printk(KERN_INFO "into %s\n", __func__);
	init_waitqueue_head(&head);
	init_waitqueue_entry(&data, current);
	add_wait_queue(&head, &data);
	t = sleep_on_timeout(&head, 100);
	printk(KERN_INFO "sleep_on_timeout result t :%ld in child\n", t);
#if 0
void complete(struct completion *x)
#endif
	printk(KERN_INFO "befor complet parent state :%ld\n",
			current->real_parent->state);
	complete(&comple);
	printk(KERN_INFO "after complete comple.done :%d\n", comple.done);
	printk(KERN_INFO "after complete parent state :%ld\n",
			current->real_parent->state);
	printk(KERN_INFO "out %s\n", __func__);
	return 0;
}

static int __init wait_for_completion_interruptible_timeout_init(void)
{
	pid_t pid;
	struct pid *kpid;
	struct task_struct *task;
	wait_queue_t data;
	int t;
	printk(KERN_INFO "wait_for_completion_interruptible_timeout_init\n");
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
unsigned long __sched
wait_for_completion_interruptible_timeout(struct completion *x,
					  unsigned long timeout)
#endif
	printk(KERN_INFO "wait_for_completion_interruptible_timeout\n");
	t = wait_for_completion_interruptible_timeout(&comple, 200);
	printk(KERN_INFO "wait_for_completion_interruptible_timeout result t :%d\n", t);
	return 0;
}

static void __exit wait_for_completion_interruptible_timeout_exit(void)
{
	printk(KERN_INFO "wait_for_completion_interruptible_timeout_exit\n");
}

module_init(wait_for_completion_interruptible_timeout_init);
module_exit(wait_for_completion_interruptible_timeout_exit);

MODULE_LICENSE("GPL");
