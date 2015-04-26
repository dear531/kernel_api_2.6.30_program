/*
 * usage:
 * load:
 * $ insmod sym_a.ko
 * $ insmod find_symbol.ko 
 * unload:
 * $ rmmod find_symbol.ko
 * $ insmod sym_a.ko
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init find_symbol_init(void)
{
#if 0
const struct kernel_symbol *find_symbol(const char *name,
                                        struct module **owner,
                                        const unsigned long **crc,
                                        bool gplok,
                                        bool warn)
#endif
	const char *name = "sym_a";
	const struct kernel_symbol *sym;
	struct module *owner;
	const unsigned long *crc;
	bool gplok	= true;
	bool warn	= true;
	printk(KERN_INFO "find_symbol_init\n");
	sym = find_symbol(name, &owner, &crc, gplok, warn);
	if (NULL != sym) {
		printk(KERN_INFO "name :%s\n", sym->name);
		printk(KERN_INFO "address :%lx\n", sym->value);
	}
	if (NULL != owner) {
		printk(KERN_INFO "module name :%s\n", owner->name);
	}
	if (NULL != crc) {
		printk(KERN_INFO "address :%lx\n", *crc);
	}

	return 0;
}

static void __exit find_symbol_exit(void)
{
	printk(KERN_INFO "find_symbol_exit\n");
}

module_init(find_symbol_init);
module_exit(find_symbol_exit);

MODULE_LICENSE("GPL");
