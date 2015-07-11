#include <linux/init.h>
#include <linux/module.h>
#include <linux/spinlock.h>

static int __init rwlock1_init(void)
{
	rwlock_t rwl = RW_LOCK_UNLOCKED;
	int ret;
	printk(KERN_INFO "%s\n", __func__);
	rwlock_init(&rwl);
	printk(KERN_INFO "init rwl.raw_lock.lock :%x\n", rwl.raw_lock.lock);
	ret = read_trylock(&rwl);
	printk(KERN_INFO "read_trylock result :%d\n", ret);
	printk(KERN_INFO "read_trylock rwl.raw_lock.lock :%x\n", rwl.raw_lock.lock);
	ret = read_trylock(&rwl);
	printk(KERN_INFO "second read_trylock result :%d\n", ret);
	printk(KERN_INFO "second read_trylock rwl.raw_lock.lock :%x\n", rwl.raw_lock.lock);
	ret = write_trylock(&rwl);
	printk(KERN_INFO "write_trylock result :%d\n", ret);
	printk(KERN_INFO "write_trylock rwl.raw_lock.lock :%x\n", rwl.raw_lock.lock);
	read_unlock(&rwl);
	printk(KERN_INFO "read_unlock rwl.raw_lock.lock :%x\n", rwl.raw_lock.lock);
	read_unlock(&rwl);
	printk(KERN_INFO "second read_unlock rwl.raw_lock.lock :%x\n", rwl.raw_lock.lock);
	ret = write_trylock(&rwl);
	printk(KERN_INFO "second write_trylock result :%d\n", ret);
	printk(KERN_INFO "second write_trylock rwl.raw_lock.lock :%x\n", rwl.raw_lock.lock);
	ret = write_trylock(&rwl);
	printk(KERN_INFO "3 write_trylock result :%d\n", ret);
	printk(KERN_INFO "3 write_trylock rwl.raw_lock.lock :%x\n", rwl.raw_lock.lock);
	write_unlock(&rwl);
	printk(KERN_INFO "write_unlock rwl.raw_lock.lock :%x\n", rwl.raw_lock.lock);
	return 0;
}

static void __exit rwlock_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(rwlock1_init);
module_exit(rwlock_exit);

MODULE_LICENSE("GPL");
