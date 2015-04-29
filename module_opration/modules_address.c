#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

int tmpname_module(void)
{
	return 0;
}

static int __init module_address_init(void)
{
	/*
	 * find_module();
	 * struct module *__module_address(unsigned long addr)
	 * __module_address();
	 * module_refcount();
	 */
	struct module *ret = NULL;
	printk(KERN_INFO "module address function init\n");
	preempt_disable();
	ret = __module_address((unsigned long)tmpname_module);
	preempt_enable();
	printk(KERN_INFO "name :%s\n", ret->name);
	printk(KERN_INFO "state :%d\n", ret->state);
	printk(KERN_INFO "version :%s\n", ret->version);
	printk(KERN_INFO "size :%d\n", ret->core_size);
	printk(KERN_INFO "tmpname_module address :%p, ret->module_core: %p\n",
			tmpname_module, ret->module_core);
	printk(KERN_INFO "count :%d\n", module_refcount(ret));
	return 0;
}

static void __exit module_address_exit(void)
{
	printk(KERN_INFO "module address function exit\n");
}

module_init(module_address_init);
module_exit(module_address_exit);

MODULE_LICENSE("GPL");
