#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
unsigned int irq = 2;
#if 0
typedef irqreturn_t (*irq_handler_t)(int, void *);
#endif
irqreturn_t irq_thread(int data, void *dev_id)
{
	printk(KERN_INFO "%s\n", __func__);
	return IRQ_NONE;
}

irqreturn_t irq_handler(int data, void *dev_id)
{
	printk(KERN_INFO "%s\n", __func__);
	return IRQ_NONE;
}

static int __init set_irq_chip_init(void)
{
	int ret;
	printk(KERN_INFO "set_irq_chip_init\n");
#if 0
extern int __must_check
request_threaded_irq(unsigned int irq, irq_handler_t handler,
		     irq_handler_t thread_fn,
		     unsigned long flags, const char *name, void *dev);
#endif
	ret = request_threaded_irq(irq, irq_handler, irq_thread, IRQF_DISABLED,
			"A_NEW_DEVICE", NULL);
	printk(KERN_INFO "request_threaded_irq result :%d\n", ret);
#if 0
int set_irq_chip(unsigned int irq, struct irq_chip *chip)
#endif
	ret = set_irq_chip(irq, NULL);
	printk(KERN_INFO "set_irq_chip result :%d\n", ret);
	return 0;
}

static void __exit set_irq_chip_exit(void)
{
	printk(KERN_INFO "set_irq_chip_exit\n");
	free_irq(irq, NULL);
}

module_init(set_irq_chip_init);
module_exit(set_irq_chip_exit);

MODULE_LICENSE("GPL");
