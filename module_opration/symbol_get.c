#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

extern int sym_a(void);
static char *name = "sym_a";
static int __init symbol_get_init(void)
{
	void *address;
	printk(KERN_INFO "symbol_get_init\n");
	address = __symbol_get(name);
	if (NULL != address) {
		printk(KERN_INFO "sym_a address %lx\n",
				(unsigned long)address);
	} else {
		printk(KERN_INFO "does not exist address\n");
	}
	printk(KERN_INFO "sym_a function address :%lx\n",
			(unsigned long)sym_a);
	return 0;
}

static void __exit symbol_get_exit(void)
{
	printk(KERN_INFO "symbol_get_exit\n");
	__symbol_put(name);
}

module_init(symbol_get_init);
module_exit(symbol_get_exit);

MODULE_LICENSE("GPL");
