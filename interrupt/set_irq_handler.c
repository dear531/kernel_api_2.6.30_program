#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
#include <linux/interrupt.h>
#include <linux/irq.h>

static int irq = 11;

irqreturn_t irq_handler(int irq, void *dev_id)
{
	printk(KERN_INFO "irq num is :%d irq_handler\n", irq);
	printk(KERN_INFO "dev_id :%p\n", dev_id);
	return IRQ_WAKE_THREAD;
}
#if 0
typedef irqreturn_t (*irq_handler_t)(int, void *);
#endif
irqreturn_t irq_handler_func(int irq, void *dev_id)
{
	printk(KERN_INFO "irq num is :%d irq_handler_func\n", irq);
	printk(KERN_INFO "dev_id :%p\n", dev_id);
	return IRQ_HANDLED;
}

static int __init set_irq_handler_init(void)
{
	int result;
	printk(KERN_INFO "set_irq_handler_init\n");
#if 0
extern int __must_check
request_threaded_irq(unsigned int irq, irq_handler_t handler,
		     irq_handler_t thread_fn,
		     unsigned long flags, const char *name, void *dev);
#endif
	result = request_threaded_irq(irq, irq_handler, irq_handler_func,
			IRQF_DISABLED, "A_NEW_DEVICE", NULL);
#if 0
void
__set_irq_handler(unsigned int irq, irq_flow_handler_t handle, int is_chained,
		  const char *name)
#endif
	__set_irq_handler(irq, NULL, 1, "A-NEW-DEVICE");
	enable_irq(irq);
	printk(KERN_INFO "resulte :%d\n", result);
	printk(KERN_INFO "out set_irq_handler_init\n");
	return 0;
}

static void __exit set_irq_handler_exit(void)
{
	free_irq(irq, NULL);
	printk(KERN_INFO "set_irq_handler_exit\n");
}

module_init(set_irq_handler_init);
module_exit(set_irq_handler_exit);

MODULE_LICENSE("GPL");
