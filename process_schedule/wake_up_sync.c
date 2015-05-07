#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static wait_queue_head_t  head;
static int myfunc(void *arg)
{
	printk(KERN_INFO "in the child thread\n");
	printk(KERN_INFO "wake_up_sync befor parent state current->real_parent->state :%ld\n",
			current->real_parent->state);
	__wake_up_sync(&head, TASK_ALL, 0);
	printk(KERN_INFO "wake_up_sync after parent state current->real_parent->state :%ld\n",
			current->real_parent->state);
	printk(KERN_INFO "out the child thread\n");
	return 0;
}
static int __init wake_up_sync_init(void)
{
	wait_queue_t data;
	pid_t pid;
	long time;
	printk(KERN_INFO "wake_up_sync_init\n");
	/* init head fo wait queue */
#if 0
void init_waitqueue_head(wait_queue_head_t *q)
#endif
	init_waitqueue_head(&head);
	/* init curret process data */
#if 0
static inline void init_waitqueue_entry(wait_queue_t *q, struct task_struct *p)
#endif
	init_waitqueue_entry(&data, current);
	/* add current data into head */
#if 0
void add_wait_queue(wait_queue_head_t *q, wait_queue_t *wait)
#endif
	add_wait_queue(&head, &data);
	/* create kernel thread */
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	time = sleep_on_timeout(&head, 2000);
	printk(KERN_INFO "time :%ld\n", time);

	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	if (0 >= pid) {
		printk(KERN_INFO "kernel_thread error\n");
		goto finish;
	}
#if 0
long __sched sleep_on_timeout(wait_queue_head_t *q, long timeout)
#endif
	time = sleep_on_timeout(&head, 100);
	printk(KERN_INFO "time :%ld\n", time);
finish:
	return 0;
}

static void __exit wake_up_sync_exit(void)
{
	printk(KERN_INFO "wake_up_sync_exit\n");
}

module_init(wake_up_sync_init);
module_exit(wake_up_sync_exit);

MODULE_LICENSE("GPL");
