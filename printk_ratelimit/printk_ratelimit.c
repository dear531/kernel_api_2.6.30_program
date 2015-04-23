#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init printk_rate_init(void)
{
	int i;
	for (i = 0; 10 > i; i++) {
		if (printk_ratelimit())
			printk(KERN_INFO "printk_ratelimit %d\n", i);
	}
	return 0;
}

static void __exit printk_rate_exit(void)
{
	printk(KERN_INFO "printk_ratelimit exit\n");
}

module_init(printk_rate_init);
module_exit(printk_rate_exit);

MODULE_LICENSE("GPL");
