#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int data = 0;

static int fun_a(void)
{
	int i = 0;
	printk(KERN_INFO "i :%d\n", i);
	return 0;
}
EXPORT_SYMBOL(fun_a);

static int __init find_module_init(void)
{
	char *name = "find_module";
	struct module *mod;
	printk(KERN_INFO "find_module_init\n");
	mod = find_module(name);
	if (NULL != mod) {
#if 0
	/* Here are the sizes of the init and core sections */
	unsigned int init_size, core_size;

	/* The size of the executable code in each section.  */
	unsigned int init_text_size, core_text_size;
#endif
		printk(KERN_INFO "state :%d\n", mod->state);
		printk(KERN_INFO "data :%d\n", data);
		printk(KERN_INFO "name :%s\n", mod->name);
		printk(KERN_INFO "init size :%d, core size :%d\n",
				mod->init_size, mod->core_size);
		printk(KERN_INFO "executable init size :%d, core size :%d\n",
				mod->init_text_size, mod->core_text_size);
		printk(KERN_INFO "count :%d\n",
				module_refcount(mod));
	}
	return 0;
}

static void __exit find_module_exit(void)
{
	printk(KERN_INFO "find_module_exit\n");
}

module_init(find_module_init);
module_exit(find_module_exit);

MODULE_LICENSE("GPL");
