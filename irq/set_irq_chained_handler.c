#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
unsigned int irq = 11;
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
static int __init set_irq_chained_handler_init(void)
{
	printk(KERN_INFO "set_irq_chained_handler_init\n");
#if 0
extern int __must_check
request_threaded_irq(unsigned int irq, irq_handler_t handler,
		     irq_handler_t thread_fn,
		     unsigned long flags, const char *name, void *dev);
#endif
	request_threaded_irq(irq, irq_thread, irq_handler,
			IRQF_DISABLED, "A_NEW_DEVICE", NULL);
	set_irq_chained_handler(irq, NULL);
#if 0
void disable_irq(unsigned int irq)
#endif
	disable_irq(irq);
	enable_irq(irq);
	return 0;
}

static void __exit set_irq_chained_handler_exit(void)
{
	free_irq(irq, NULL);
	printk(KERN_INFO "set_irq_chained_handler_exit\n");
}

module_init(set_irq_chained_handler_init);
module_exit(set_irq_chained_handler_exit);

MODULE_LICENSE("GPL");
