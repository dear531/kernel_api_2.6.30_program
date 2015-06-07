#include <linux/init.h>
#include <linux/module.h>
#include <linux/gfp.h>

char *p = NULL, *new = NULL;

static int __init krealloc_init(void)
{
	int ret = 0, i;
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
void *krealloc(const void *p, size_t new_size, gfp_t flags)
#endif
	new = krealloc(p, 26, GFP_KERNEL);
	if (NULL == new) {
		ret = -ENOMEM;
		printk(KERN_INFO "krealloc error \n");
		goto finish;
	}
	for (i = 0; 26 > i; i++) {
		printk(KERN_INFO "%c", new[i]);
	}
finish:
	return ret;
}

static void __exit krealloc_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (NULL != new) {
#if 0
void __free_pages(struct page *page, unsigned int order)
#endif
		__free_pages(new, 0);
	}
}

module_init(krealloc_init);
module_exit(krealloc_exit);

MODULE_LICENSE("GPL");
