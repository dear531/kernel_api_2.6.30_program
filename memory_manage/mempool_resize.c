#include <linux/init.h>
#include <linux/module.h>
#include <linux/mempool.h>
struct kmem_cache *cache = NULL;
mempool_t *pool = NULL;
static int __init mempool_resize_init(void)
{
	int ret = 0, result;
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct kmem_cache *
kmem_cache_create (const char *name, size_t size, size_t align,
	unsigned long flags, void (*ctor)(void *))
#endif
	cache = kmem_cache_create("mycache", 10000, 0, SLAB_HWCACHE_ALIGN, NULL);
	if (NULL == cache) {
		ret = -ENOMEM;
		printk(KERN_INFO "kmem_cache_create error\n");
		goto finish;
	}
#if 0
mempool_t *mempool_create(int min_nr, mempool_alloc_t *alloc_fn,
				mempool_free_t *free_fn, void *pool_data)
#endif
	pool = mempool_create(5, mempool_alloc_slab, mempool_free_slab, cache);
	if (NULL == pool) {
		ret = -ENOMEM;
		printk(KERN_INFO "mempool_create error \n");
		goto finish;
	}
	printk(KERN_INFO "mempool_create pool->min_nr :%d\n", pool->min_nr);
#if 0
int mempool_resize(mempool_t *pool, int new_min_nr, gfp_t gfp_mask)
#endif
	result = mempool_resize(pool, 6, GFP_KERNEL);
	if (0 > result) {
		ret = result;
		printk(KERN_INFO "mempool_resize error \n");
		goto finish;
	}
	printk(KERN_INFO "mempool_resize pool->mim_nr :%d\n", pool->min_nr);
finish:
	return ret;
}

static void __exit mempool_resize_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (NULL != pool) {
#if 0
void mempool_destroy(mempool_t *pool)
#endif
		mempool_destroy(pool);
		pool = NULL;
	}
	if (NULL != cache) {
#if 0
void kmem_cache_destroy(struct kmem_cache *cachep)
#endif
		kmem_cache_destroy(cache);
		cache = NULL;
	}
}

module_init(mempool_resize_init);
module_exit(mempool_resize_exit);

MODULE_LICENSE("GPL");
