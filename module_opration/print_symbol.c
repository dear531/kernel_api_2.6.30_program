#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kallsyms.h>

static int a_symbol(void)
{
	return 0;
}

EXPORT_SYMBOL(a_symbol);

unsigned long	address;
static int __init print_symbol_init(void)
{
	/*
	 * void __print_symbol(const char *fmt, unsigned long address)
	 */
	const char	*fmt = "this is first part %s\n";
	struct module 	*fmodule;
	char		*name = NULL;
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
#if 0
	/* Here are the sizes of the init and core sections */
	unsigned int init_size, core_size;

	/* The size of the executable code in each section.  */
	unsigned int init_text_size, core_text_size;
#endif
		fmt = "this is second part :%s\n";
		__print_symbol(fmt, address);
		printk(KERN_INFO "init size :%x, core_size :%x\n",
				fmodule->init_size, fmodule->core_size);
		printk(KERN_INFO "text size :%x, text core_size :%x\n",
				fmodule->init_text_size, fmodule->core_text_size);
	}
	address = (unsigned long)a_symbol + 5;
	fmt = "this is thrid part :%s\n";
	__print_symbol(fmt, address);
	return 0;
}

static void __exit print_symbol_exit(void)
{
	const char	*fmt = "this is exit part %s\n";
	printk(KERN_INFO "print_symbol_exit\n");
	address = (unsigned long)__builtin_return_address(0);
	__print_symbol(fmt, address);
}

module_init(print_symbol_init);
module_exit(print_symbol_exit);

MODULE_LICENSE("GPL");
