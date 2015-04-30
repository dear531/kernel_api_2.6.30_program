#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int fun_tmp(void)
{
	return 0;
}
EXPORT_SYMBOL(fun_tmp);

static int fun_addr(void)
{
	unsigned long address;
	const struct kernel_symbol *sym;
	printk(KERN_INFO "fun_addr\n");
	address = (unsigned long)__builtin_return_address(0);
	printk(KERN_INFO "builtin_return_address :%lx\n",
			address);
	address = (unsigned long)fun_addr;
	printk(KERN_INFO "fun_addr :%lx\n",
			address);
	sym = find_symbol("fun_addr", NULL, NULL, true, true);
	if (NULL != sym) {
		printk(KERN_INFO "sym->name :%s, sym->value :%lx\n",
				sym->name, sym->value);
	}
	return 0;
}
EXPORT_SYMBOL(fun_addr);

static int __init fun_addr_init(void)
{
	printk(KERN_INFO "fun_addr_init\n");
	return 0;
}

static void __exit fun_addr_exit(void)
{
	printk(KERN_INFO "fun_addr_exit\n");
}

module_init(fun_addr_init);
module_exit(fun_addr_exit);

MODULE_LICENSE("GPL");
