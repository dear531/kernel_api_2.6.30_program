#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#if 0
typedef irqreturn_t (*irq_handler_t)(int, void *);
#endif
irqreturn_t handler_irq_func(int data, void *dev_id)
{
	printk(KERN_INFO "into %s\n", __func__);
	printk(KERN_INFO "out %s\n", __func__);
	return IRQ_NONE;
}
#if 0
struct irqaction {
	irq_handler_t handler;
	unsigned long flags;
	cpumask_t mask;
	const char *name;
	void *dev_id;
	struct irqaction *next;
	int irq;
	struct proc_dir_entry *dir;
	irq_handler_t thread_fn;
	struct task_struct *thread;
	unsigned long thread_flags;
};
#endif
struct irqaction act = {
	.handler = handler_irq_func,
	.flags = IRQF_DISABLED,
	.name = "A_NEW_DIVICE",
	.dev_id = NULL,
	.irq = 11,
};
static int __init remove_irq_init(void)
{
	int ret;
	printk(KERN_INFO "remove_irq_init\n");
#if 0
int request_irq(unsigned int irq,
		irq_handler_t handler,
		unsigned long flags, const char *devname, void *dev_id)
#endif
	ret = request_irq(act.irq, act.handler, act.flags,
			act.name, act.dev_id);
	printk(KERN_INFO "request_irq result : %d\n", ret);
	return 0;
}

static void __exit remove_irq_exit(void)
{
	printk(KERN_INFO "remove_irq_exit\n");
#if 0
void remove_irq(unsigned int irq, struct irqaction *act)
#endif
	remove_irq(act.irq, &act);
}

module_init(remove_irq_init);
module_exit(remove_irq_exit);

MODULE_LICENSE("GPL");
