#include <linux/init.h>
#include <linux/module.h>
#include <linux/mempool.h>

void *pool_data = (int *)8192;
void *p = NULL;
static int __init mempool_kmalloc_init(void)
{
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
void *mempool_kmalloc(gfp_t gfp_mask, void *pool_data)
#endif
	p = mempool_kmalloc(GFP_KERNEL, pool_data);
	if (NULL == p) {
		ret = -ENOMEM;
		printk(KERN_INFO "mempool_kmalloc error\n");
		goto finish;
	}
	printk(KERN_INFO "p :%#p\n", p);
finish:
	return 0;
}

static void __exit mempool_kmalloc_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (NULL != p) {
#if 0
void mempool_kfree(void *element, void *pool_data)
#endif
		mempool_kfree(p, pool_data);
		p = NULL;
	}
}

module_init(mempool_kmalloc_init);
module_exit(mempool_kmalloc_exit);

MODULE_LICENSE("GPL");
