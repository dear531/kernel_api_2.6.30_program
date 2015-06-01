#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
unsigned int irq = 3;
#if 0
typedef irqreturn_t (*irq_handler_t)(int, void *);
#endif
irqreturn_t irq_handler(int irq, void *dev_id)
{
	printk(KERN_INFO "%s\n", __func__);
	return IRQ_HANDLED;
}
static int __init set_irq_wake_init(void)
{
	int ret;
	printk(KERN_INFO "%s\n", __func__);
#if 0
int request_irq(unsigned int irq,
		irq_handler_t handler,
		unsigned long flags, const char *devname, void *dev_id)
#endif
	ret = request_irq(irq, irq_handler, IRQF_DISABLED, "A_NEW_DEVICE", NULL);
	printk(KERN_INFO "request_irq result :%d\n", ret);
	ret = set_irq_wake(irq, 0);
	printk(KERN_INFO "set irq wake is 0 result :%d\n", ret);
	ret = set_irq_wake(irq, 1);
	printk(KERN_INFO "set irq wake is 1 result :%d\n", ret);

	return 0;
}

static void __exit set_irq_wake_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	free_irq(irq, NULL);
}

module_init(set_irq_wake_init);
module_exit(set_irq_wake_exit);

MODULE_LICENSE("GPL");
