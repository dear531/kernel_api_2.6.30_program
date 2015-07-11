#include <linux/init.h>
#include <linux/module.h>
#include <linux/spinlock.h>

static int __init spin_lock_init1(void)
{
	spinlock_t lock = SPIN_LOCK_UNLOCKED;
	int ret;
	printk(KERN_INFO "%s\n", __func__);
	spin_lock_init(&lock);
	printk(KERN_INFO "init lock.raw_lock.slock :%x\n",
			lock.raw_lock.slock);
	ret = spin_can_lock(&lock);
	printk(KERN_INFO "spin_can_lock result :%d\n", ret);
	printk(KERN_INFO "spin_can_lock lock.raw_lock.slock :%x\n",
			lock.raw_lock.slock);
	spin_lock(&lock);
	printk(KERN_INFO "spin_lock lock.raw_lock.slock :%x\n",
			lock.raw_lock.slock);
	ret = spin_trylock(&lock);
	printk(KERN_INFO "spin_trylock result :%d\n", ret);
	printk(KERN_INFO "spin_trylock lock.raw_lock.slock :%x\n",
			lock.raw_lock.slock);
	ret = spin_can_lock(&lock);
	printk(KERN_INFO "second spin_can_lock result :%d\n", ret);
	printk(KERN_INFO "second spin_can_lock lock.raw_lock.slock :%x\n",
			lock.raw_lock.slock);
	spin_unlock(&lock);
	printk(KERN_INFO "spin_unlock lock.raw_lock.slock :%x\n",
			lock.raw_lock.slock);
	ret = spin_is_locked(&lock);
	printk(KERN_INFO "spin_is_locked result %d\n", ret);
	printk(KERN_INFO "spin_is_locked lock.raw_lock.slock :%x\n",
			lock.raw_lock.slock);
	return 0;
}

static void __exit spin_lock_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(spin_lock_init1);
module_exit(spin_lock_exit);

MODULE_LICENSE("GPL");
