#include <linux/module.h>
#include <linux/init.h>

static void symbol_export_print(void)
{
	printk(KERN_ALERT "I'm symbol export\n");
}
EXPORT_SYMBOL(symbol_export_print);

static int __init my_symbol_export_init(void)
{
	printk(KERN_ALERT "my_symbol_export_init\n");
	symbol_export_print();
	return 0;
}
static void __exit my_symbol_export_exit(void)
{
	printk(KERN_ALERT "my_symbol_export_exit\n");
}
module_init(my_symbol_export_init);
module_exit(my_symbol_export_exit);

MODULE_LICENSE("GPL");
MODULE_AUTHOR("zhangly");
MODULE_VERSION("2.6.30");
MODULE_ALIAS("test_macro_for_kernel");
