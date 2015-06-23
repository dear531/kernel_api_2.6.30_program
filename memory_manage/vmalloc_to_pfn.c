#include <linux/init.h>
#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/mm.h>

void *p = NULL;

static int __init vmalloc_to_pfn_init(void)
{
	unsigned long to_pfn = 0;
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
void *vmalloc(unsigned long size)
#endif
	p = vmalloc(8192);
	if (NULL == p) {
		ret = -ENOMEM;
		printk(KERN_INFO "vmalloc error\n");
		goto finish;
	}
#if 0
unsigned long vmalloc_to_pfn(const void *addr)
#endif
	to_pfn = vmalloc_to_pfn(p);
	printk(KERN_INFO "p to_pfn :%ld\n", to_pfn);
	to_pfn = vmalloc_to_pfn(p + 4097);
	printk(KERN_INFO "p + 4097 to_pfn :%ld\n", to_pfn);
finish:
	return ret;
}

static void __exit vmalloc_to_pfn_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
#if 0
void vfree(const void *addr)
#endif
	if (NULL != p) {
		vfree(p);
		p = NULL;
	}
}

module_init(vmalloc_to_pfn_init);
module_exit(vmalloc_to_pfn_exit);

MODULE_LICENSE("GPL");
