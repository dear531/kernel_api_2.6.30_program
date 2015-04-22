#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include "pdebug.h"

static int __init pdebug_init(void)
{
	PDEBUG(KERN_INFO "this is kernel debug info\n");
	return 0;
}

static void __exit pdebug_exit(void)
{
	PDEBUG(KERN_INFO "kernel debug exit\n");
}

module_init(pdebug_init);
module_exit(pdebug_exit);

MODULE_LICENSE("GPL");
