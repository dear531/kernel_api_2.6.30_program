#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	printk(KERN_INFO "child pid :%d state :%ld in child\n",
			current->pid, current->state);
	printk(KERN_INFO "parent pid :%d state :%ld in parent\n",
			current->real_parent->pid, current->real_parent->state);
	return 0;
}

static int __init interruptible_sleep_on_init(void)
{
	wait_queue_head_t head;
	wait_queue_t data;
	pid_t pid;
	printk(KERN_INFO "interruptible_sleep_on_init\n");
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
void __sched interruptible_sleep_on(wait_queue_head_t *q)
#endif
	printk(KERN_INFO "child pid :%d parent pid :%d in parent\n",
			pid, current->pid);
	printk(KERN_INFO "parent state :%ld befor interruptible_sleep_on\n",
			current->state);
#if 1
	/* input ctrl + c on terminal for to kill sleep and coutinue when insmod the module */
	interruptible_sleep_on(&head);
#endif
	printk(KERN_INFO "parent state :%ld after interruptible_sleep_on\n",
			current->state);
	return 0;
}

static void __exit interruptible_sleep_on_exit(void)
{
	printk(KERN_INFO "interruptible_sleep_on_exit\n");
}

module_init(interruptible_sleep_on_init);
module_exit(interruptible_sleep_on_exit);

MODULE_LICENSE("GPL");
