/*
 * usage:
 * run:
 * 1.$ insmod sym_a.ko
 * 2.$ insmod module_state.ko
 * unload:
 * 1.$ rmmod module_state
 * 2.$ rmmod sym_a
 */
#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

static int __init module_state_init(void)
{
	struct module *mod;
	printk(KERN_INFO "module_state_init\n");
	printk(KERN_INFO "name :%s state :%d\n", THIS_MODULE->name, THIS_MODULE->state);
	mod = find_module("sym_a");
	if (NULL != mod) {
		printk(KERN_INFO "name :%s state :%d\n",
				mod->name, mod->state);
	}
	return 0;
}

static void __exit module_state_exit(void)
{
	printk(KERN_INFO "module_state_exit\n");
	printk(KERN_INFO "name :%s state :%d\n", THIS_MODULE->name, THIS_MODULE->state);
}

module_init(module_state_init);
module_exit(module_state_exit);

MODULE_LICENSE("GPL");
