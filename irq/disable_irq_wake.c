#include <linux/init.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/kernel.h>
#include <linux/interrupt.h>

unsigned int irq = 3;

irqreturn_t irq_handler_handler(int irq, void *dev_id)
{
	return IRQ_NONE;
}
static int __init disable_irq_wake_init(void)
{
	int ret_request, ret_wake;
	printk(KERN_INFO "disable_irq_wake_init\n");
#if 0
typedef irqreturn_t (*irq_handler_t)(int, void *);
int request_irq(unsigned int irq,
		irq_handler_t handler,
		unsigned long flags, const char *devname, void *dev_id)
#endif
	ret_request = request_irq(irq, irq_handler_handler, IRQF_DISABLED, "NEW_DEVICE", NULL);
	ret_wake = disable_irq_wake(irq);
	printk("request_irq result :%d\n", ret_request);
	printk("disable_irq_wake result :%d\n", ret_wake);
	return 0;
}

static void __exit disable_irq_wake_exit(void)
{
	printk(KERN_INFO "disable_irq_wake_exit\n");
}

module_init(disable_irq_wake_init);
module_exit(disable_irq_wake_exit);

MODULE_LICENSE("GPL");
