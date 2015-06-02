#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/gfp.h>

unsigned long addr;
static int __init __get_free_pages_init(void)
{
	printk(KERN_INFO "%s\n", __func__);
	addr = __get_free_pages(GFP_KERNEL, 3);
	if (0 != addr)
		printk(KERN_INFO "__get_free_pages addr %lu\n", addr);
	else 
		printk(KERN_INFO "__get_free_pages error\n");
	return 0;
}

static void __exit __get_free_pages_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	free_pages(addr, 3);
}

module_init(__get_free_pages_init);
module_exit(__get_free_pages_exit);

MODULE_LICENSE("GPL");
