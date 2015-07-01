#include <linux/init.h>
#include <linux/module.h>

#define DOWN_WRITE_FLAG	0

static int __init down_read_init(void)
{
	struct rw_semaphore sem;
	int ret;
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct rw_semaphore {
	long			count;
#define RWSEM_UNLOCKED_VALUE		0x0000000000000000L
#define RWSEM_ACTIVE_BIAS		0x0000000000000001L
#define RWSEM_ACTIVE_MASK		0x00000000ffffffffL
#define RWSEM_WAITING_BIAS		(-0x0000000100000000L)
#define RWSEM_ACTIVE_READ_BIAS		RWSEM_ACTIVE_BIAS
#define RWSEM_ACTIVE_WRITE_BIAS		(RWSEM_WAITING_BIAS + RWSEM_ACTIVE_BIAS)
	spinlock_t		wait_lock;
	struct list_head	wait_list;
};
static inline void init_rwsem(struct rw_semaphore *sem)
#endif
	init_rwsem(&sem);
#if 0
void __sched down_read(struct rw_semaphore *sem)
#endif
	printk(KERN_INFO "1 :sem.count :%ld, sem.wait_lock :%d\n",
			sem.count, sem.wait_lock);
	if (DOWN_WRITE_FLAG) {
		down_write(&sem);
		printk(KERN_INFO "2 :sem.count :%ld, sem.wait_lock :%d\n",
			sem.count, sem.wait_lock);
	}
#if 0
int down_read_trylock(struct rw_semaphore *sem)
#endif
	ret = down_read_trylock(&sem);
	printk(KERN_INFO "down_read_trylock result :%d\n", ret);
	printk(KERN_INFO "3 :sem.count :%ld, sem.wait_lock :%d\n",
			sem.count, sem.wait_lock);
	ret = down_read_trylock(&sem);
	printk(KERN_INFO "down_read_trylock result :%d\n", ret);
	printk(KERN_INFO "4 :sem.count :%ld, sem.wait_lock :%d\n",
			sem.count, sem.wait_lock);
	while (0 == ret && 0 < sem.count) {
		up_read(&sem);
	}
	return 0;
}

static void __exit down_read_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(down_read_init);
module_exit(down_read_exit);

MODULE_LICENSE("GPL");
