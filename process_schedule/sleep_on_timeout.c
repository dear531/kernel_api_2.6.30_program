#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	printk(KERN_INFO "current pid :%d in child\n",
			current->pid);
#if 0
int wake_up_process(struct task_struct *p)
#endif
	printk(KERN_INFO "befor wake_up_process parent state :%ld\n",
			current->real_parent->state);
	wake_up_process(current->real_parent);
	printk(KERN_INFO "after wake_up_process parent state :%ld\n",
			current->real_parent->state);
	return 0;
}

static int __init sleep_on_timeout_init(void)
{
	pid_t pid;
	wait_queue_head_t head;
	wait_queue_t data;
	printk(KERN_INFO "sleep_on_time_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	printk(KERN_INFO "child pid :%d in parent\n", pid);
#if 0
void init_waitqueue_head(wait_queue_head_t *q)
#endif
	init_waitqueue_head(&head);
#if 0
static inline void init_waitqueue_entry(wait_queue_t *q, struct task_struct *p)
#endif
	init_waitqueue_entry(&data, current);
#if 0
void add_wait_queue(wait_queue_head_t *q, wait_queue_t *wait)
#endif
	add_wait_queue(&head, &data);
#if 0
long __sched sleep_on_timeout(wait_queue_head_t *q, long timeout)
#endif
	sleep_on_timeout(&head, 100);

	return 0;
}

static void __exit sleep_on_timeout_exit(void)
{
	printk(KERN_INFO "sleep_on_time_exit\n");
}

module_init(sleep_on_timeout_init);
module_exit(sleep_on_timeout_exit);

MODULE_LICENSE("GPL");
