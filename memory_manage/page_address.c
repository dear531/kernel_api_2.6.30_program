#include <linux/init.h>
#include <linux/module.h>
#include <linux/mm.h>

struct page *pages = NULL;
void *p = NULL;

static int __init page_address_init1(void)
{
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
static inline struct page *
alloc_pages(gfp_t gfp_mask, unsigned int order)
#endif
	pages = alloc_pages(GFP_KERNEL, 0);
	if (NULL == pages) {
		ret = -ENOMEM;
		printk(KERN_INFO "alloc_pages error \n");
		goto finish;
	}
	printk(KERN_INFO "pages :%#p\n", pages);
#if 0
void *page_address(struct page *page)
#endif
	p = page_address(pages);
	printk(KERN_INFO "p :%#p\n", p);
finish:
	return 0;
}

static void __exit page_address_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
#if 0
void free_pages(unsigned long addr, unsigned int order)
#endif
	if (NULL != pages) {
		__free_pages(pages, 0);
		pages = NULL;
	}
}

module_init(page_address_init1);
module_exit(page_address_exit);

MODULE_LICENSE("GPL");
