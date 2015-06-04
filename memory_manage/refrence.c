#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>

#include "share.h"

static int __init refrence_init(void)
{
	printk(KERN_INFO "%s\n", __func__);
	null_pointer_refrence(NULL);
	return 0;
}

static void __exit refrence_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(refrence_init);
module_exit(refrence_exit);

MODULE_LICENSE("GPL");
