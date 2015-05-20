#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init init_waitqueue_entry_init(void)
{
	wait_queue_t data;
	printk(KERN_INFO "init_waitqueue_entry_init\n");
#if 0
static inline void init_waitqueue_entry(wait_queue_t *q, struct task_struct *p)
#endif
	init_waitqueue_entry(&data, current);
	printk(KERN_INFO "defualt_wait_function :%p, current :%p\n",
			default_wake_function, current);
	printk(KERN_INFO "data.func :%p, data.private :%p\n",
			data.func, data.private);
	printk(KERN_INFO "data.flags :%d\n",
			data.flags);
	return 0;
}

static void __exit init_waitqueue_entry_exit(void)
{
	printk(KERN_INFO "init_waitqueue_entry_exit\n");
}

module_init(init_waitqueue_entry_init);
module_exit(init_waitqueue_entry_exit);

MODULE_LICENSE("GPL");
