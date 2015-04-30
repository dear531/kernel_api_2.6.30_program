#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init use_module_init(void)
{
	const struct kernel_symbol *sym;
	struct module *mod;
	printk(KERN_INFO "use_module_init\n");
#if 0
const struct kernel_symbol *find_symbol(const char *name,
					struct module **owner,
					const unsigned long **crc,
					bool gplok,
					bool warn)
#endif
	sym = find_symbol("fun_addr", &mod, NULL, true, true);
	if (NULL != sym && NULL != mod) {
		printk(KERN_INFO "befor use %s count :%d\n",
				mod->name, module_refcount(mod));
		if (0 != use_module(THIS_MODULE, mod)) {
			printk(KERN_INFO "after use %s count :%d\n",
				mod->name, module_refcount(mod));
		}
	}
	return 0;
}

static void __exit use_module_exit(void)
{
	printk(KERN_INFO "use_module_exit\n");
}

module_init(use_module_init);
module_exit(use_module_exit);

MODULE_LICENSE("GPL");
