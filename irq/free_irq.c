#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>

unsigned int irq = 11;

irqreturn_t irq_handler_func(int data, void *dev_id)
{
	printk(KERN_INFO "into %s\n", __func__);
	printk(KERN_INFO "irq number :%d\n", data);
	printk(KERN_INFO "curent->pid :%d in func %s\n",
			current->pid, __func__);
	printk(KERN_INFO "out %s\n", __func__);
	return IRQ_NONE;
}

static int __init free_irq_init(void)
{
	int ret;
#if 0
int request_irq(unsigned int irq,
		irq_handler_t handler,
		unsigned long flags, const char *devname, void *dev_id)
#endif
	printk(KERN_INFO "into %s\n", __func__);
	printk(KERN_INFO "free_irq_init\n");
	ret = request_irq(irq, irq_handler_func, IRQF_DISABLED,
			"A_NEW_DEVICE", NULL);
	printk(KERN_INFO "request_irq result :%d\n", ret);
#if 0
	disable_irq(irq);
	enable_irq(irq);
#endif
	printk(KERN_INFO "curent->pid :%d in func %s\n",
			current->pid, __func__);
	printk(KERN_INFO "out %s\n", __func__);
	return 0;
}

static void __exit free_irq_exit(void)
{
	printk(KERN_INFO "free_irq_exit\n");
#if 0
void free_irq(unsigned int irq, void *dev_id)
#endif
	free_irq(irq, NULL);
	printk(KERN_INFO "irq number :%d\n", irq);
}

module_init(free_irq_init);
module_exit(free_irq_exit);

MODULE_LICENSE("GPL");
