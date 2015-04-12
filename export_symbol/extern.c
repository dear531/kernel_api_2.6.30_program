#include <linux/init.h>
#include <linux/module.h>
extern void symbol_export_print(void);
static int extern_func_init(void)
{
	printk(KERN_ALERT "I'm extern func\n");
	symbol_export_print();
	return 0;
}

static void extern_func_exit(void)
{
	printk(KERN_ALERT "extern exit\n");
}
module_init(extern_func_init);
module_exit(extern_func_exit);
MODULE_LICENSE("GPL");
