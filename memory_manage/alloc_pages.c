#include <linux/init.h>
#include <linux/module.h>
#include <linux/gfp.h>
#include <linux/mm.h>

struct page *pages = NULL;

static int __init alloc_pages_init(void)
{
	printk(KERN_INFO "%s\n", __func__);
#if 0
static inline struct page *
alloc_pages(gfp_t gfp_mask, unsigned int order)
#endif
	pages = alloc_pages(GFP_KERNEL, 3);
	if (NULL == pages) {
		return -ENOMEM;
	}
	printk(KERN_INFO "pages :%#lx\n", (unsigned long)pages);
	printk(KERN_INFO "mem_map :%#lx\n", (unsigned long)mem_map);
	printk(KERN_INFO "pages - mem_map :%#lx\n", (unsigned long)pages - (unsigned long) mem_map);
	printk(KERN_INFO "(pages - mem_map) * 4096 :%#lx\n",
			((unsigned long)pages - (unsigned long)mem_map) * 4096);
#if 0
void *page_address(struct page *page)
#endif
	printk(KERN_INFO "page_address(pages) :%#lx\n",
			(unsigned long)page_address(pages));
	return 0;
}

static void __exit alloc_pages_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	__free_pages(pages, 3);
}

module_init(alloc_pages_init);
module_exit(alloc_pages_exit);

MODULE_LICENSE("GPL");
