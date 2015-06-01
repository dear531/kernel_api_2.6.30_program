#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
unsigned int irq = 10;
#if 0
typedef irqreturn_t (*irq_handler_t)(int, void *);
#endif

irqreturn_t irq_handler(int irq, void *dev_id)
{
	printk(KERN_INFO "%s\n", __func__);
	return IRQ_WAKE_THREAD;
}

irqreturn_t irq_thread(int irq, void *dev_id)
{
	printk(KERN_INFO "%s\n", __func__);
	return IRQ_HANDLED;
}

static int __init set_irq_type_init(void)
{
	int ret;
	printk(KERN_INFO "set_irq_type_init\n");
#if 0
extern int __must_check
request_threaded_irq(unsigned int irq, irq_handler_t handler,
		     irq_handler_t thread_fn,
		     unsigned long flags, const char *name, void *dev);
#endif
	ret = request_threaded_irq(irq, irq_handler, irq_thread,
			IRQF_DISABLED, "A_NEW_DEVICE", NULL);
	printk(KERN_INFO "request_thread_irq result :%d\n", ret);
#if 0
int set_irq_type(unsigned int irq, unsigned int type)
#endif
	set_irq_type(irq, IRQ_TYPE_SENSE_MASK);
	disable_irq(irq);
	enable_irq(irq);
	return 0;
}

static void __exit set_irq_type_exit(void)
{
	printk(KERN_INFO "set_irq_type_exit\n");
	free_irq(irq, NULL);
}

module_init(set_irq_type_init);
module_exit(set_irq_type_exit);

MODULE_LICENSE("GPL");
