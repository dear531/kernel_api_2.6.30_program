#include <linux/init.h>
#include <linux/module.h>

#include "share.h"

void null_pointer_refrence(struct costum *a)
{
	printk(KERN_INFO "a->a :%d, a->b :%d\n",
			a->a, a->b);
}

EXPORT_SYMBOL(null_pointer_refrence);

MODULE_LICENSE("GPL");


