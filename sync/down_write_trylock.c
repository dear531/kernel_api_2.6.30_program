#include <linux/init.h>
#include <linux/module.h>

static int __init down_write_trylock_init(void)
{
	struct rw_semaphore rwsem;
	int ret;
	printk(KERN_INFO "%s\n", __func__);
#if 0
static inline void init_rwsem(struct rw_semaphore *sem)
#endif
	init_rwsem(&rwsem);
	printk(KERN_INFO "init_rwsem rwsem.count :%ld, rwsem.wait_lock :%d\n",
			rwsem.count, rwsem.wait_lock);
#if 0
void __sched down_write(struct rw_semaphore *sem)
#endif
	down_write(&rwsem);
	printk(KERN_INFO "down_write rwsem.count :%ld, rwsem.wait_lock :%d\n",
			rwsem.count, rwsem.wait_lock);
#if 0
int down_write_trylock(struct rw_semaphore *sem)
#endif
	ret = down_write_trylock(&rwsem);
	printk(KERN_INFO "down_write_trylock result :%d\n", ret);
	printk(KERN_INFO "down_write_trylock rwsem.count :%ld, rwsem.wait_lock :%d\n",
			rwsem.count, rwsem.wait_lock);
	if (0 == ret) {
#if 0
void up_write(struct rw_semaphore *sem)
#endif
		up_write(&rwsem);
	}
	printk(KERN_INFO "up_write rwsem.count :%ld, rwsem.wait_lock :%d\n",
			rwsem.count, rwsem.wait_lock);
	return 0;
}

static void __exit down_write_trylock_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(down_write_trylock_init);
module_exit(down_write_trylock_exit);

MODULE_LICENSE("GPL");
