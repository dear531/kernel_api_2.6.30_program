#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
unsigned int irq = 10;

irqreturn_t irq_handler(int irq, void *dev_id)
{
	printk(KERN_INFO "%s\n", __func__);
	return IRQ_NONE;
}

struct irqaction act = {
	.irq		= 10,
	.handler	= irq_handler,
	.name		= "A_NEW_DEVICE",
	.thread_flags	= IRQF_DISABLED,
	.dev_id		= NULL,
};

static int __init setup_irq_init(void)
{
	int ret;
	printk(KERN_INFO "%s\n", __func__);
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
int setup_irq(unsigned int irq, struct irqaction *act)
#endif
	ret = setup_irq(irq, &act);
	printk(KERN_INFO "setup_irq result :%d\n", ret);
	return 0;
}

static void __exit setup_irq_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	remove_irq(irq, &act);
}

module_init(setup_irq_init);
module_exit(setup_irq_exit);

MODULE_LICENSE("GPL");
