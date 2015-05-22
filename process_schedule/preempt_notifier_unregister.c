#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

static struct preempt_notifier notifier;
static struct preempt_ops ops;
static int myfunc(void *arg)
{
	printk(KERN_INFO "into %s\n", __func__);
	printk(KERN_INFO "child pid :%d, parent pid :%d\n",
			current->pid, current->real_parent->pid);
	printk(KERN_INFO "out %s\n", __func__);
	return 0;
}
static void sched_in(struct preempt_notifier *notifier, int cpu)
{
	printk(KERN_INFO "into %s function\n", __func__);
	printk(KERN_INFO "current->pid :%d, cpu :%d\n",
			current->pid, cpu);
	printk(KERN_INFO "out %s function\n", __func__);
}
static void sched_out(struct preempt_notifier *notifier,
		  struct task_struct *next)
{
	printk(KERN_INFO "into %s\n", __func__);
	printk(KERN_INFO "current->pid :%d, next->pid :%d\n",
			current->pid, next->pid);
	printk(KERN_INFO "out :%s\n", __func__);
}
static int __init preempt_notifier_unregister_init(void)
{
	pid_t pid;
	printk(KERN_INFO "preempt_notifier_unregister_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	printk(KERN_INFO "child pid :%d, parent pid :%d\n",
			pid, current->pid);
#if 0
static inline void preempt_notifier_init(struct preempt_notifier *notifier,
				     struct preempt_ops *ops)
#endif
	ops.sched_in = sched_in;
	ops.sched_out = sched_out;
	preempt_notifier_init(&notifier, &ops);
#if 0
void preempt_notifier_register(struct preempt_notifier *notifier)
#endif
	printk(KERN_INFO "preempt_notifier_register\n");
	preempt_notifier_register(&notifier);
	/* flag of unregister */
#if 0
	printk(KERN_INFO "preempt_notifier_unregister\n");
	preempt_notifier_unregister(&notifier);
#endif
	return 0;
}

static void __exit preempt_notifier_unregister_exit(void)
{
	printk(KERN_INFO "preempt_notifier_unregister_exit\n");
}

module_init(preempt_notifier_unregister_init);
module_exit(preempt_notifier_unregister_exit);

MODULE_LICENSE("GPL");
