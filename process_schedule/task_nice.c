#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

static int __init task_nice_init(void)
{
	printk(KERN_INFO "task_nice_init\n");
#if 0
int task_nice(const struct task_struct *p)
#endif
	printk(KERN_INFO "priority :%d\n", task_nice(current));
	printk(KERN_INFO "prio :%d, static_prio :%d, normal_prio :%d\n",
			current->prio, current->static_prio, current->normal_prio);
	return 0;
}

static void __exit task_nice_exit(void)
{
	printk(KERN_INFO "task_nice_exit\n");
}

module_init(task_nice_init);
module_exit(task_nice_exit);

MODULE_LICENSE("GPL");
