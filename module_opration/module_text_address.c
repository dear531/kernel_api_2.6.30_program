/*
 * $ insmod module_text_address.ko
 * $ cat /proc/kallsyms |grep -e var_b -e fun_a
 * e185c000 t fun_a	[module_text_address]
 * e185c624 b var_b	[module_text_address]
 * node t:text b:bss
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int fun_a(void)
{
	return 0;
}

int var_b = 0;
static void printk_module_info(struct module *mod)
{
	if (NULL != mod) {
		/* 
		 * unsigned int init_text_size, core_text_size;
		 * __module_ref_addr();
		 * __module_text_address();
		 * __module_address();
		 */
		printk(KERN_INFO "name :%s\n", mod->name);
		printk(KERN_INFO "init text:%d\n", mod->init_text_size);
		printk(KERN_INFO "core text:%d\n", mod->core_text_size);
	} else {
		printk(KERN_INFO "is not text\n");
	}
}
static int __init module_text_address_init(void)
{
	/*
	 * __module_text_address();
	 * struct module *__module_text_address(unsigned long addr)
	 */
	struct module *ret;

	printk(KERN_INFO "module_text_address init\n");
	printk(KERN_INFO "this is module name :%s\n", THIS_MODULE->name);

	preempt_disable();
	ret = __module_text_address((unsigned long)fun_a);
	preempt_enable();
	printk_module_info(ret);

	preempt_disable();
	ret = __module_text_address((unsigned long)&var_b);
	preempt_enable();

	printk_module_info(ret);
	return 0;
}

static void __exit module_text_address_exit(void)
{
	printk(KERN_INFO "module_text_address exit\n");
}

module_init(module_text_address_init);
module_exit(module_text_address_exit);

MODULE_LICENSE("GPL");
