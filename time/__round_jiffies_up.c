#include <linux/init.h>
#include <linux/module.h>
#include <linux/timer.h>

static int __init __round_jiffies_up_init(void)
{
	unsigned long j = jiffies, result0, result1;
	printk(KERN_INFO "%s\n", __func__);
	printk(KERN_INFO "j :%ld\n", j);
#if 0
unsigned long __round_jiffies_up(unsigned long j, int cpu)
#endif
	result0 = __round_jiffies_up(j, 0);
	result1 = __round_jiffies_up(j, 1);
	printk(KERN_INFO "result0 :%ld, result1 :%ld\n",
			result0, result1);
	return 0;
}

static void __exit __round_jiffies_up_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(__round_jiffies_up_init);
module_exit(__round_jiffies_up_exit);

MODULE_LICENSE("GPL");
