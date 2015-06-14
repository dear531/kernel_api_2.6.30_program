#include <linux/init.h>
#include <linux/module.h>
#include <linux/mempool.h>

void *pool_data = (int *)2;
char *p = NULL;

static int __init mempool_alloc_pages_init(void)
{
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
void *mempool_alloc_pages(gfp_t gfp_mask, void *pool_data)
#endif
	p = mempool_alloc_pages(GFP_KERNEL, pool_data);
	if (NULL == p) {
		ret = -ENOMEM;
		goto finish;
		printk(KERN_INFO "mempool_alloc_pages error\n");
	}
	printk(KERN_INFO "%#p\n", p);
finish:
	return 0;
}

static void __exit mempool_alloc_pages_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (NULL != p) {
		mempool_free_pages(p, pool_data);
	}
}

module_init(mempool_alloc_pages_init);
module_exit(mempool_alloc_pages_exit);

MODULE_LICENSE("GPL");
