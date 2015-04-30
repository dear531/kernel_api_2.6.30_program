/*
 * usage:
 * 1.$ insmod sym_fun_addr.ko
 * 2.$ insmod symbol_put_addr.ko
 * unload:
 * 1.$ rmmod symbol_put_addr
 * 2.$ rmmod sym_fun_addr
 */
#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

extern int fun_addr(void);

const struct kernel_symbol *sym;
static int __init symbol_put_addr_init(void)
{
#if 0
const struct kernel_symbol *find_symbol(const char *name,
					struct module **mod,
					const unsigned long **crc,
					bool gplok,
					bool warn)
#endif
	struct module *mod;
	const unsigned long *crc;
	void *address;
	printk(KERN_INFO "symbol_put_addr_init\n");
	sym = find_symbol("fun_addr", &mod, &crc, true, true);
	if (NULL != sym) {
		printk(KERN_INFO "sym->name :%s,sym->value:%lx\n",
				sym->name, sym->value);
		if (NULL != crc) {
			printk(KERN_INFO "*crc: %lx, crc :%p\n", *crc, crc);
		}
		printk(KERN_INFO "befor get count :%d\n",
				module_refcount(mod));
		address = __symbol_get(sym->name);
		printk(KERN_INFO "mod name :%s, mod address :%p\n",
				mod->name, mod->module_core);
		printk(KERN_INFO "after get befor put count :%d\n",
				module_refcount(mod));
		symbol_put_addr(address);
		printk(KERN_INFO "after put count :%d\n",
				module_refcount(mod));
	}
	return 0;
}

static void __exit symbol_put_addr_exit(void)
{
	printk(KERN_INFO "symbol_put_addr_exit\n");
}

module_init(symbol_put_addr_init);
module_exit(symbol_put_addr_exit);

MODULE_LICENSE("GPL");
