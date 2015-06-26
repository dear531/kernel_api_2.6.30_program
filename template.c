#include <linux/init.h>
#include <linux/module.h>

static int __init template_init(void)
{
	printk(KERN_INFO "%s\n", __func__);
	return 0;
}

static void __exit template_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(template_init);
module_exit(template_exit);

MODULE_LICENSE("GPL");
