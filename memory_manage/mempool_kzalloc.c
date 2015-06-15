#include <linux/init.h>
#include <linux/module.h>
#include <linux/mempool.h>

void *pool_data = (int *)8192;
char *p = NULL;
mempool_t *pool = NULL;

static int __init mempool_kzalloc_init(void)
{
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
void *mempool_kzalloc(gfp_t gfp_mask, void *pool_data)
#endif
	p = mempool_kzalloc(GFP_KERNEL, pool_data);
	if (NULL == p) {
		ret = -ENOMEM;
		printk(KERN_INFO "mempool_kzalloc error \n");
		goto finish;
	}
	printk(KERN_INFO "p :%#p, p[100] :%d\n", p, p[100]);
#if 0
static inline mempool_t *mempool_create_kzalloc_pool(int min_nr, size_t size)
#endif
	pool = mempool_create_kzalloc_pool(5, 8192);
	if (NULL == pool) {
		ret = -ENOMEM;
		printk(KERN_INFO "mempool_create_kzalloc_pool error \n");
		goto finish;
	}
	printk(KERN_INFO "pool :%#p\n", pool);
finish:
	return ret;
}

static void __exit mempool_kzalloc_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
#if 0
void mempool_kfree(void *element, void *pool_data)
#endif
	if (NULL != p) {
		mempool_kfree(p, pool_data);
		p = NULL;
	}
	if (NULL != pool) {
#if 0
void mempool_destroy(mempool_t *pool)
#endif
		mempool_destroy(pool);
		pool = NULL;
	}
}

module_init(mempool_kzalloc_init);
module_exit(mempool_kzalloc_exit);

MODULE_LICENSE("GPL");
