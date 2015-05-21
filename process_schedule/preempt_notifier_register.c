#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/preempt.h>
#include <linux/pid.h>

struct preempt_notifier notifier;
struct preempt_ops ops;

void sched_in(struct preempt_notifier *notifier, int cpu)
{
	printk(KERN_INFO "into sched_in function\n");
	printk(KERN_INFO "sched_in cpu :%d\n", cpu);
	printk(KERN_INFO "current->pid :%d\n",
			current->pid);
	printk(KERN_INFO "out sched_in function\n");
}
void sched_out(struct preempt_notifier *notifier,
			  struct task_struct *next)
{
	printk(KERN_INFO "into sched_out function\n");
	printk(KERN_INFO "current->pid :%d\n",
			current->pid);
	printk(KERN_INFO "next->pid :%d\n",
			next->pid);
	printk(KERN_INFO "out sched_out function\n");
}

static int myfunc(void *arg)
{
	printk(KERN_INFO "into %s function\n", __func__);
	printk(KERN_INFO "child pid :%d\n", current->pid);
	printk(KERN_INFO "out %s function\n", __func__);
	return 0;
}
static int __init preempt_notifier_register_init(void)
{
	pid_t pid;
	printk(KERN_INFO "preempt_notifier_register_init\n");
#if 0
struct preempt_ops {
	void (*sched_in)(struct preempt_notifier *notifier, int cpu);
	void (*sched_out)(struct preempt_notifier *notifier,
			  struct task_struct *next);
};
struct preempt_notifier {
	struct hlist_node link;
	struct preempt_ops *ops;
};
static inline void preempt_notifier_init(struct preempt_notifier *notifier,
				     struct preempt_ops *ops)
#endif
	ops.sched_in = sched_in;
	ops.sched_out = sched_out;
	preempt_notifier_init(&notifier, &ops);
#if 0
void preempt_notifier_register(struct preempt_notifier *notifier)
#endif
	preempt_notifier_register(&notifier);
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	printk(KERN_INFO "child pid :%d, parent pid :%d\n",
			pid, current->pid);
	return 0;
}

static void __exit preempt_notifier_register_exit(void)
{
	printk(KERN_INFO "preempt_notifier_regisger_exit\n");
}

module_init(preempt_notifier_register_init);
module_exit(preempt_notifier_register_exit);

MODULE_LICENSE("GPL");
