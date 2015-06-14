#include <linux/init.h>
#include <linux/module.h>
#include <linux/mempool.h>

struct kmem_cache *cache = NULL;
void *p = NULL;

static int __init mempool_alloc_slab_init(void)
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
		printk(KERN_INFO "kmem_cache_create error\n");
		goto finish;
	}
#if 0
void *mempool_alloc_slab(gfp_t gfp_mask, void *pool_data)
#endif
	p = mempool_alloc_slab(GFP_KERNEL, cache);
	if (NULL == p) {
		ret = -ENOMEM;
		printk(KERN_INFO "mempool_alloc_slab error \n");
		goto finish;
	}
	printk(KERN_INFO "p :%#p\n", p);
finish:
	return 0;
}

static void __exit mempool_alloc_slab_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (NULL != p) {
#if 0
void mempool_free_slab(void *element, void *pool_data)
#endif
		mempool_free_slab(p, cache);
	}
	if (NULL != cache) {
#if 0
void kmem_cache_destroy(struct kmem_cache *cachep)
#endif
		kmem_cache_destroy(cache);
	}
}

module_init(mempool_alloc_slab_init);
module_exit(mempool_alloc_slab_exit);

MODULE_LICENSE("GPL");
