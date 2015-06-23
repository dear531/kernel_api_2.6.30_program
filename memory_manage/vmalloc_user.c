#include <linux/init.h>
#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/mm.h>

void *p = NULL;

static int __init vmalloc_user_init(void)
{
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
void *vmalloc_user(unsigned long size)
#endif
	p = vmalloc_user(8192);
	if (NULL == p) {
		ret = -ENOMEM;
		printk(KERN_INFO "vmalloc_user error\n");
		goto finish;
	}
	printk(KERN_INFO "p :%#p\n", p);
finish:
	return ret;
}

static void __exit vmalloc_user_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (NULL != p) {
		vfree(p);
		p = NULL;
	}
}

module_init(vmalloc_user_init);
module_exit(vmalloc_user_exit);

MODULE_LICENSE("GPL");
