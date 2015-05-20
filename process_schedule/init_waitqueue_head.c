#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init init_waitqueue_head_init(void)
{
	wait_queue_head_t head; 
	printk(KERN_INFO "init_waitqueue_head_init\n");
#if 0
void init_waitqueue_head(wait_queue_head_t *q)
#endif
	init_waitqueue_head(&head);
	printk(KERN_INFO "head.task_list.next :%p,head.task_list.prev :%p, head.task_list :%p\n", 
			head.task_list.next, head.task_list.prev, &head.task_list);
	return 0;
}

static void __exit init_waitqueue_head_exit(void)
{
	printk(KERN_INFO "init_waitqueue_head_exit\n");
}

module_init(init_waitqueue_head_init);
module_exit(init_waitqueue_head_exit);

MODULE_LICENSE("GPL");
