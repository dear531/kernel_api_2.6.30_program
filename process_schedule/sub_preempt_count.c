#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

static int __init sub_preempt_count_init(void)
{
	struct thread_info *info;
	printk(KERN_INFO "sub_preempt_count_init\n");
#if 0
static inline struct thread_info *current_thread_info(void)
#endif
	info = current_thread_info();
	printk(KERN_INFO "origin info->preempt_count :%d\n",
			info->preempt_count);
	add_preempt_count(1);
	printk(KERN_INFO "after add_preempt_count info->preempt_count :%d\n",
			info->preempt_count);
	sub_preempt_count(1);
	printk(KERN_INFO "after sub_preempt_count info->preempt_count :%d\n",
			info->preempt_count);
	return 0;
}

static void __exit sub_preempt_count_exit(void)
{
	printk(KERN_INFO "sub_preempt_count_exit\n");
}

module_init(sub_preempt_count_init);
module_exit(sub_preempt_count_exit);

MODULE_LICENSE("GPL");
