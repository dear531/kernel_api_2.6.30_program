#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int sym_a(void)
{
	return 0;
}
EXPORT_SYMBOL(sym_a);

static int __init symbol_get_init(void)
{
	printk(KERN_INFO "sym_a_init\n");
	return 0;
}

static void __exit symbol_get_exit(void)
{
	printk(KERN_INFO "sym_a_exit\n");
}

module_init(symbol_get_init);
module_exit(symbol_get_exit);

MODULE_LICENSE("GPL");
