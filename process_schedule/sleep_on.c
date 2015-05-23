#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	printk(KERN_INFO "current->pid :%d in child\n",
			current->pid);
	return 0;
}

static int __init sleep_on_init(void)
{
	pid_t pid;
	wait_queue_head_t head;
	wait_queue_t data;

	printk(KERN_INFO "sleep_on_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
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
void __sched sleep_on(wait_queue_head_t *q)
#endif
	sleep_on(&head);

	return 0;
}

static void __exit sleep_on_exit(void)
{
	printk(KERN_INFO "sleep_on_exit\n");
}

module_init(sleep_on_init);
module_exit(sleep_on_exit);

MODULE_LICENSE("GPL");
