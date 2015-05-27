#include <linux/init.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/irqnr.h>

#if 0
# if defined(CONFIG_ALPHA_LEGACY_START_ADDRESS)
#  define NR_IRQS      (128)           /* max is RAWHIDE/TAKARA */
# else
#  define NR_IRQS      (32768 + 16)    /* marvel - 32 pids */
# endif
#endif
unsigned int irq = 11;

#if 0
typedef irqreturn_t (*irq_handler_t)(int, void *);
#endif
irqreturn_t irq_handler_func(int irq, void *dev_id)
{
	printk(KERN_INFO "this is %s irq :%d\n", __func__, irq);
	return IRQ_NONE;
}

static int __init disable_irq_nosync_init(void)
{
	int ret;
	printk(KERN_INFO "disable_irq_nosync_init\n");
#if 0
int request_irq(unsigned int irq,
		irq_handler_t handler,
		unsigned long flags, const char *devname, void *dev_id)
#endif
	printk(KERN_INFO "after request_irq\n");
	ret = request_irq(irq, irq_handler_func, IRQF_DISABLED, "A_NEW_DEVICE", NULL);
	printk(KERN_INFO "befor request_irq\n");
	printk(KERN_INFO "request_irq result :%d\n", ret);
	disable_irq_nosync(irq);
	enable_irq(irq);
	printk(KERN_INFO "out %s\n", __func__);
	return 0;
}

static void __exit disable_irq_nosync_exit(void)
{
	printk(KERN_INFO "disable_irq_nosync_exit\n");
#if 0
void free_irq(unsigned int irq, void *dev_id)
#endif
	free_irq(irq, NULL);
}

module_init(disable_irq_nosync_init);
module_exit(disable_irq_nosync_exit);

MODULE_LICENSE("GPL");
