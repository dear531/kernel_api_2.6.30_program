#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
unsigned int irq = 11;
#if 0
typedef irqreturn_t (*irq_handler_t)(int, void *);
enum irqreturn {
	IRQ_NONE,
	IRQ_HANDLED,
	IRQ_WAKE_THREAD,
};
#endif
irqreturn_t irq_handler(int data, void *dev_id)
{
	printk(KERN_INFO "%s\n", __func__);
	return IRQ_NONE;
}

#if 0
typedef irqreturn_t (*irq_handler_t)(int, void *);
#endif
irqreturn_t irq_thread(int data, void *dev_id)
{
	printk(KERN_INFO "%s\n", __func__);
	return IRQ_NONE;
}

static int __init request_threaded_irq_init(void)
{
	int ret;
	printk(KERN_INFO "request_threaded_irq_init\n");
#if 0
extern int __must_check
request_threaded_irq(unsigned int irq, irq_handler_t handler,
		     irq_handler_t thread_fn,
		     unsigned long flags, const char *name, void *dev);
#endif
	ret = request_threaded_irq(irq, irq_handler, irq_thread,
			IRQF_DISABLED, "A_NEW_DEVICE", NULL);
#if 0
void disable_irq(unsigned int irq)
#endif
	disable_irq(irq);
	enable_irq(irq);
	printk(KERN_INFO "requst_threaded_irq result :%d\n", ret);
	return 0;
}

static void __exit request_threaded_irq_exit(void)
{
	free_irq(irq, NULL);
	printk(KERN_INFO "request_threaded_irq_exit\n");
}

module_init(request_threaded_irq_init);
module_exit(request_threaded_irq_exit);

MODULE_LICENSE("GPL");
