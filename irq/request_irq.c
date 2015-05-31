#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#if 0
enum irqreturn {
	IRQ_NONE,
	IRQ_HANDLED,
	IRQ_WAKE_THREAD,
};
#endif
unsigned int irq = 11;
irqreturn_t irq_request_func(int data, void *dev_id)
{
	printk(KERN_INFO "%s\n", __func__);
	return IRQ_NONE;
}
static int __init request_irq_init(void)
{
	int ret;
	printk(KERN_INFO "request_irq_init\n");
#if 0
int request_irq(unsigned int irq,
		irq_handler_t handler,
		unsigned long flags, const char *devname, void *dev_id)
#endif
	ret = request_irq(irq, irq_request_func, IRQF_DISABLED,
			"A_NEW_DEVICE", NULL);
	printk(KERN_INFO "request_irq result :%d\n", ret);
	return 0;
}

static void __exit request_irq_exit(void)
{
	printk(KERN_INFO "request_irq_exit\n");
	free_irq(irq, NULL);
}

module_init(request_irq_init);
module_exit(request_irq_exit);

MODULE_LICENSE("GPL");
