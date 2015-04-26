#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kallsyms.h>

static int a_symbol(void)
{
	return 0;
}

EXPORT_SYMBOL(a_symbol);

static int __init print_symbol_init(void)
{
	/*
	 * void __print_symbol(const char *fmt, unsigned long address)
	 */
	const char	*fmt = "this is first part %s\n";
	struct module 	*fmodule;
	char		*name = NULL;
	unsigned long	address;
	printk(KERN_INFO "print_symbol_init\n");
	address = (unsigned long)__builtin_return_address(0);
	__print_symbol(fmt, address);
	name = "print_symbol";
	/*
	 * struct module *find_module(const char *name)
	 */
	fmodule = find_module(name);
	if (NULL != fmodule) {
		printk(KERN_INFO "module name %s\n",
				fmodule->name);
		address = (unsigned long)fmodule->module_core;
		fmt = "this is second part :%s\n";
		__print_symbol(fmt, address);
	}
	address = (unsigned long)a_symbol + 5;
	fmt = "this is thrid part :%s\n";
	__print_symbol(fmt, address);
	return 0;
}

static void __exit print_symbol_exit(void)
{
	printk(KERN_INFO "print_symbol_exit\n");
}

module_init(print_symbol_init);
module_exit(print_symbol_exit);

MODULE_LICENSE("GPL");
