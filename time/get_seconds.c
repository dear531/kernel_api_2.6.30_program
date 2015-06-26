#include <linux/init.h>
#include <linux/module.h>

static int __init template_init(void)
{
	unsigned long second = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
unsigned long get_seconds(void)
#endif
	second = get_seconds();
	printk(KERN_INFO "second :%ld\n", second);
	return 0;
}

static void __exit template_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(template_init);
module_exit(template_exit);

MODULE_LICENSE("GPL");
