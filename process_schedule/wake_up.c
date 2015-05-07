#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

wait_queue_head_t head;
static int myfunc(void *arg)
{
	printk(KERN_INFO "in the kernel thread function\n");
	printk(KERN_INFO "parent befor wake_up state :%ld in child\n",
			current->real_parent->state);
#if 0
void __wake_up(wait_queue_head_t *q, unsigned int mode,
			int nr_exclusive, void *key)
#endif
	__wake_up(&head, TASK_ALL, 0, NULL);
	printk(KERN_INFO "parent after wake_up state :%ld in child\n",
			current->real_parent->state);
	printk(KERN_INFO "child current->pid :%d in child\n",
			current->pid);
	printk(KERN_INFO "out the kernel thread function\n");
	return 0;
}

static int __init wake_up_init(void)
{
	pid_t pid;
	wait_queue_t data;
	long time;
	printk(KERN_INFO "wake_up_init\n");
#if 0
void init_waitqueue_head(wait_queue_head_t *q)
#endif
	printk(KERN_INFO "init_waitqueue_head\n");
	init_waitqueue_head(&head);
#if 0
static inline void init_waitqueue_entry(wait_queue_t *q, struct task_struct *p)
#endif
	printk(KERN_INFO "init_waitqueue_entry\n");
	init_waitqueue_entry(&data, current);
#if 0
void add_wait_queue(wait_queue_head_t *q, wait_queue_t *wait)
#endif
	printk(KERN_INFO "add_wait_queque\n");
	add_wait_queue(&head, &data);
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
#if 0
long __sched sleep_on_timeout(wait_queue_head_t *q, long timeout)
#endif
	printk(KERN_INFO "sleep_on_timeout\n");
	time = sleep_on_timeout(&head, 100);
	printk(KERN_INFO "parent pid current->pid :%d in parent\n",
			current->pid);
	printk(KERN_INFO "kernel_thread result :%d\n", pid);
	printk(KERN_INFO "time :%ld\n", time);
	return 0;
}

static void __exit wake_up_exit(void)
{
	printk(KERN_INFO "wake_up_exit\n");
}

module_init(wake_up_init);
module_exit(wake_up_exit);

MODULE_LICENSE("GPL");
