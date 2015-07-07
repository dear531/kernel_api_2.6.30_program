#include <linux/init.h>
#include <linux/module.h>

static int __init downgrade_write_init(void)
{
	struct rw_semaphore sem;
	int ret;
	printk(KERN_INFO "%s\n", __func__);
#if 0
static inline void init_rwsem(struct rw_semaphore *sem)
#endif
	init_rwsem(&sem);
	printk(KERN_INFO "init_rwsem sem.count :%ld, sem.wait_lock :%d\n",
			sem.count, sem.wait_lock);
#if 0
void __sched down_write(struct rw_semaphore *sem)
#endif
	down_write(&sem);
	printk(KERN_INFO "down_write sem.count :%ld, sem.wait_lock :%d\n",
			sem.count, sem.wait_lock);
#if 0
int down_read_trylock(struct rw_semaphore *sem)
#endif
	ret = down_read_trylock(&sem);
	printk(KERN_INFO "ret :%d\n", ret);
	printk(KERN_INFO "down_read_trylock sem.count :%ld, sem.wait_lock :%d\n",
			sem.count, sem.wait_lock);
#if 0
void downgrade_write(struct rw_semaphore *sem)
#endif
	downgrade_write(&sem);
	printk(KERN_INFO "downgrade_write sem.count :%ld, sem.wait_lock :%d\n",
			sem.count, sem.wait_lock);
#if 0
void __sched down_read(struct rw_semaphore *sem)
#endif
	down_read(&sem);
	printk(KERN_INFO "down_read sem.count :%ld, sem.wait_lock :%d\n",
			sem.count, sem.wait_lock);
	while (0 != sem.count ) {
#if 0
void up_read(struct rw_semaphore *sem)
#endif
		up_read(&sem);
	}
	printk(KERN_INFO "up_read sem.count :%ld, sem.wait_lock :%d\n",
			sem.count, sem.wait_lock);
	return 0;
}

static void __exit downgrade_write_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(downgrade_write_init);
module_exit(downgrade_write_exit);

MODULE_LICENSE("GPL");
