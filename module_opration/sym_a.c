#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/kallsyms.h>

static int sym_a(void)
{
	char buff[KSYM_SYMBOL_LEN] = {0};
	unsigned long address;
	const struct kernel_symbol *sym;
	printk(KERN_INFO "sym_a\n");
	address = (unsigned long)__builtin_return_address(0);
	printk(KERN_INFO "builtin_return_address :%lx\n",
			address);
	address = (unsigned long)sym_a;
	printk(KERN_INFO "sym_a :%lx\n",
			address);
	sym = find_symbol("sym_a", NULL, NULL, true, true);
	if (NULL != sym) {
		printk(KERN_INFO "sym->name :%s, sym->value :%lx\n",
				sym->name, sym->value);
	}
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
