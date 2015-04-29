#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init module_put_init(void)
{
	char *fmodule = "sym_a";
	struct module *mod = NULL;
	printk(KERN_INFO "module_put_init\n");
	mod = find_module(fmodule);
	if (NULL != mod) {
		printk(KERN_INFO "befor put module ref count :%d\n",
				module_refcount(mod));
		module_put(mod);
		printk(KERN_INFO "after put module ref count :%d\n",
				module_refcount(mod));
	}
	return 0;
}

static void __exit module_put_exit(void)
{
	printk(KERN_INFO "module_put_exit\n");
}

module_init(module_put_init);
module_exit(module_put_exit);

MODULE_LICENSE("GPL");
