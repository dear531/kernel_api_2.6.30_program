#include <linux/init.h>
#include <linux/module.h>
#include <linux/hardirq.h>

static int __init spin_lock_bh_init(void)
{
	spinlock_t lock = SPIN_LOCK_UNLOCKED;
	printk(KERN_INFO "%s\n", __func__);
	spin_lock_init(&lock);
	printk(KERN_INFO "spin_lock_init lock.raw_lock.slock :%x\n",
			lock.raw_lock.slock);
	printk(KERN_INFO "spin_lock_init in_softirq %lx\n", in_softirq());
	spin_lock_bh(&lock);
	printk(KERN_INFO "spin_lock_bh lock.raw_lock.slock :%x\n",
			lock.raw_lock.slock);
	printk(KERN_INFO "spin_lock_bh in_softirq %lx\n", in_softirq());
	spin_unlock_bh(&lock);
	printk(KERN_INFO "spin_unlock_bh lock.raw_lock.slock :%x\n",
			lock.raw_lock.slock);
	printk(KERN_INFO "spin_unlock_bh in_softirq %lx\n", in_softirq());
	return 0;
}

static void __exit spin_lock_bh_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(spin_lock_bh_init);
module_exit(spin_lock_bh_exit);

MODULE_LICENSE("GPL");
