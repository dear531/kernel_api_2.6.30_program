#include <linux/init.h>
#include <linux/module.h>
#include <linux/semaphore.h>

static int __init down_init(void)
{
	
	struct semaphore sema;
	int ret;
	printk(KERN_INFO "%s\n", __func__);
#if 0
static inline void sema_init(struct semaphore *sem, int val)
#endif
#if 1
	sema_init(&sema, 5);
#else
	sema_init(&sema, 0);
#endif
#if 0
struct semaphore {
	spinlock_t		lock;
	unsigned int		count;
	struct list_head	wait_list;
};
void down(struct semaphore *sem)
#endif
	printk(KERN_INFO "sema.lock :%d\n", sema.lock.raw_lock);
	printk(KERN_INFO "sema.count :%d\n", sema.count);
#if 0
int down_interruptible(struct semaphore *sem)
#endif
	ret = down_interruptible(&sema);
	printk(KERN_INFO "ret :%d\n", ret);
	printk(KERN_INFO "sema.lock :%d\n", sema.lock.raw_lock);
	printk(KERN_INFO "sema.count :%d\n", sema.count);
	return 0;
}

static void __exit down_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(down_init);
module_exit(down_exit);

MODULE_LICENSE("GPL");
