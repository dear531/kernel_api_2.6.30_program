#include <linux/init.h>
#include <linux/module.h>
#include <linux/mempool.h>

static struct kmem_cache *cache = NULL;
static mempool_t *pool = NULL;

static int __init mempool_create_init(void)
{
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct kmem_cache *
kmem_cache_create (const char *name, size_t size, size_t align,
	unsigned long flags, void (*ctor)(void *))
#endif
	cache = kmem_cache_create("mycache", 1000, 0, SLAB_HWCACHE_ALIGN, NULL);
	if (NULL == cache) {
		ret = -ENOMEM;
		printk(KERN_INFO "kmem_cache_create error \n");
		goto finish;
	}
#if 0
mempool_t *mempool_create(int min_nr, mempool_alloc_t *alloc_fn,
				mempool_free_t *free_fn, void *pool_data)
#endif
	pool = mempool_create(5, mempool_alloc_slab, mempool_alloc_slab, cache);
	if (NULL == pool) {
		ret = -ENOMEM;
		printk(KERN_INFO "mempool_create error\n");
		goto finish;
	}
	printk(KERN_INFO "pool :%#p\n", pool);
finish:
	return ret;
}

static void __exit mempool_create_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
#if 0
void mempool_destroy(mempool_t *pool)
#endif
	if (NULL != pool) {
		mempool_destroy(pool);
		pool = NULL;
	}
#if 0
void kmem_cache_destroy(struct kmem_cache *cachep)
#endif
	if (NULL != cache) {
		kmem_cache_destroy(cache);
		cache = NULL;
	}
}

module_init(mempool_create_init);
module_exit(mempool_create_exit);

MODULE_LICENSE("GPL");
