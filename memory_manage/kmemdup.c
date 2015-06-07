#include <linux/init.h>
#include <linux/module.h>
#include <linux/gfp.h>

char *p = NULL;

static int __init kmemdup_init(void)
{
	char *new = NULL;
	int ret = 0;
	int i;
	printk(KERN_INFO "%s\n", __func__);
#if 0
static inline struct page *
alloc_pages(gfp_t gfp_mask, unsigned int order)
#endif
	p = alloc_pages(GFP_KERNEL, 0);
	if (NULL == p) {
		ret = -ENOMEM;
		printk(KERN_INFO "alloc_pages error\n");
		goto finish;
	}
	for (i = 0; 26 > i; i++) {
		p[i] = 'a' + i;
	}
#if 0	
void *kmemdup(const void *src, size_t len, gfp_t gfp)
#endif
	new = kmemdup(p, 26, GFP_KERNEL);
	if (NULL == new) {
		ret = -ENOMEM;
		printk(KERN_INFO "kmemdump error\n");
		goto finish;
	}
	for (i = 0; 26 > i; i++) {
		printk("%c", p[i]);
	}
	printk("\n");
finish:
	return ret;
}

static void __exit kmemdup_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
#if 0
void __free_pages(struct page *page, unsigned int order)
#endif
	if (NULL != p)
		__free_pages(p, 0);
}

module_init(kmemdup_init);
module_exit(kmemdup_exit);

MODULE_LICENSE("GPL");
