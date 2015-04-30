#include <linux/init.h>
#include <linux/module.h>

static void hello_exit(void)
{
	printk(KERN_ALERT "goodbye, cruel world\n");
}
module_exit(hello_exit);

MODULE_LICENSE("GPL");
