#include <linux/init.h>
#include <linux/module.h>

static int __init spin_lock_irq_init(void)
{
	spinlock_t lock = SPIN_LOCK_UNLOCKED;
	printk(KERN_INFO "%s\n", __func__);
	spin_lock_init(&lock);
	spin_lock_irq(&lock);
	printk(KERN_INFO "irqs_dsiabled() :%d\n", irqs_disabled());
	printk(KERN_INFO "spin_lock_irq lock.raw_lock.slock :%x\n",
			lock.raw_lock.slock);
	spin_unlock_irq(&lock);
	printk(KERN_INFO "irqs_dsiabled() :%d\n", irqs_disabled());
	printk(KERN_INFO "spin_unlock_irq lock.raw_lock.slock :%x\n",
			lock.raw_lock.slock);
	return 0;
}

static void __exit spin_lock_irq_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(spin_lock_irq_init);
module_exit(spin_lock_irq_exit);

MODULE_LICENSE("GPL");
