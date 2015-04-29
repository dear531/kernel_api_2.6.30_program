#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init module_refcount_init(void)
{
	const char *fname = "module_refcount";
	struct module *mod;
	printk(KERN_INFO "module_refcount_init\n");
	mod = find_module(fname);
	if (NULL != mod) {
		printk(KERN_INFO "mod name :%s\n",
				mod->name);
		printk(KERN_INFO "mod count %d\n",
				module_refcount(mod));
	}
	printk(KERN_INFO "this_module name :%s\n",
			THIS_MODULE->name);
	printk(KERN_INFO "this_module count :%d\n",
			module_refcount(THIS_MODULE));
	return 0;
}

static void __exit module_refcount_exit(void)
{
	printk(KERN_INFO "module_refcount_exit\n");
}

module_init(module_refcount_init);
module_exit(module_refcount_exit);

MODULE_LICENSE("GPL");
