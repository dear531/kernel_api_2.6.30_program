#include <linux/init.h>
#include <linux/module.h>
#include <linux/mm.h>

struct page *pages = NULL;

static int __init page_zone_init(void)
{
	int ret = 0;
	struct zone *zone = NULL;
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
#if 0
static inline struct zone *page_zone(struct page *page)
#endif
	zone = page_zone(pages);
	if (NULL == zone) {
		printk(KERN_INFO "page_zone wrong\n");
		goto finish;
	}
	if (is_normal(zone)) {
		printk(KERN_INFO "pages %#p is normal\n");
	}
	if (is_dma(zone)) {
		printk(KERN_INFO "pages %#p is dma\n");
	}
	if (is_highmem(zone)) {
		printk(KERN_INFO "pages %#p is highmem\n");
	}
finish:
	return ret;
}

static void __exit page_zone_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (NULL != pages) {
		__free_pages(pages, 0);
		pages = NULL;
	}
}

module_init(page_zone_init);
module_exit(page_zone_exit);

MODULE_LICENSE("GPL");
