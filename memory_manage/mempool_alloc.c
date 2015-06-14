#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>
#include <linux/mempool.h>

struct kmem_cache *cache = NULL;
mempool_t *pool = NULL;
char *p = NULL;

static int __init mempool_alloc_init(void)
{
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct kmem_cache *
kmem_cache_create (const char *name, size_t size, size_t align,
	unsigned long flags, void (*ctor)(void *))
#endif
	cache = kmem_cache_create("mycache", 10, 0, SLAB_HWCACHE_ALIGN, NULL);
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
		printk(KERN_INFO "mempool_create errror\n");
		goto finish;
	}
#if 0
void * mempool_alloc(mempool_t *pool, gfp_t gfp_mask)
#endif
	p = mempool_alloc(pool, GFP_KERNEL);
	printk(KERN_INFO "p :%#p\n", p);
#if 0
void * mempool_alloc(mempool_t *pool, gfp_t gfp_mask)
#endif
finish:
	return 0;
}

static void __exit mempool_alloc_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
#if 0
void mempool_free(void *element, mempool_t *pool)
#endif
	if (NULL != p) {
		mempool_free(p, pool);
	}
	if (NULL != pool) {
#if 0
void mempool_destroy(mempool_t *pool)
#endif
		mempool_destroy(pool);
	}
	if (NULL == cache) {
#if 0
void kmem_cache_destroy(struct kmem_cache *cachep)
#endif
		kmem_cache_destroy(cache);
	}
}

module_init(mempool_alloc_init);
module_exit(mempool_alloc_exit);

MODULE_LICENSE("GPL");
