#include <linux/init.h>
#include <linux/module.h>
#include <linux/vmalloc.h>

void *p = NULL;

static int __init vmalloc_init1(void)
{
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
void *vmalloc(unsigned long size)
#endif
	p = vmalloc(8192);
	if (NULL == p) {
		printk(KERN_INFO "vmalloc error \n");
		ret = -ENOMEM;
		goto finish;
	}
	printk(KERN_INFO "p :%#p\n", p);
finish:
	return ret;
}

static void __exit vmalloc_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (NULL != p) {
		vfree(p);
		p = NULL;
	}
}

module_init(vmalloc_init1);
module_exit(vmalloc_exit);

MODULE_LICENSE("GPL");
MODULE_VERSION("0.0.1");
