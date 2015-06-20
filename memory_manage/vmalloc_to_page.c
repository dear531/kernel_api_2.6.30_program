#include <linux/init.h>
#include <linux/module.h>
#include <linux/vmalloc.h>
#include <linux/mman.h>

void *p = NULL;

static int __init vmalloc_to_page_init(void)
{
	struct page *page = NULL;
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
	printk(KERN_INFO "p :%#p\n", p);
#if 0
struct page *vmalloc_to_page(const void *addr)
#endif
	page = vmalloc_to_page(p);
	if (NULL == page) {
		ret = -ENOMEM;
		printk(KERN_INFO "vmalloc_to_page error\n");
		goto finish;
	}
	printk(KERN_INFO "page :%#p\n", page);
finish:
	return ret;
}

static void __exit vmalloc_to_page_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (NULL != p) {
		vfree(p);
		p = NULL;
	}
}

module_init(vmalloc_to_page_init);
module_exit(vmalloc_to_page_exit);

MODULE_LICENSE("GPL");
