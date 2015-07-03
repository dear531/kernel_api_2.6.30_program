#include <linux/init.h>
#include <linux/module.h>
#include <linux/semaphore.h>

static int __init template_init(void)
{
	int ret;
	struct semaphore sem;
	printk(KERN_INFO "%s\n", __func__);
#if 0
static inline void sema_init(struct semaphore *sem, int val)
#endif
#if 0
	sema_init(&sem, 0);
#else
	sema_init(&sem, 1);
#endif
	printk(KERN_INFO "sem.count :%d\n", sem.count);
#if 0
int down_timeout(struct semaphore *sem, long jiffies)
#endif
	ret = down_timeout(&sem, 1000);
	if (0 != ret) {
		printk(KERN_INFO "down_timeout error\n");
		goto finish;
	}
finish:
	printk(KERN_INFO "sem.count :%d, ret :%d\n",
			sem.count, ret);
	return 0;
}

static void __exit template_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(template_init);
module_exit(template_exit);

MODULE_LICENSE("GPL");
