#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init module_is_live_init(void)
{
	printk(KERN_INFO "module_is_live_init\n");
	if (module_is_live(THIS_MODULE)) {
		printk(KERN_INFO "%s is not going\n", THIS_MODULE->name);
	} else {
		printk(KERN_INFO "%s is going\n", THIS_MODULE->name);
	}
	return 0;
}

static void __exit module_is_live_exit(void)
{
	printk(KERN_INFO "module_is_live_exit\n");
	if (module_is_live(THIS_MODULE)) {
		printk(KERN_INFO "%s is not going\n", THIS_MODULE->name);
	} else {
		printk(KERN_INFO "%s is going\n", THIS_MODULE->name);
	}
}

module_init(module_is_live_init);
module_exit(module_is_live_exit);

MODULE_LICENSE("GPL");
