#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>

struct kmem_cache *cache = NULL;
void *obj = NULL;

static int __init kmem_cache_alloc_init(void)
{
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct kmem_cache *
kmem_cache_create (const char *name, size_t size, size_t align,
	unsigned long flags, void (*ctor)(void *))
#endif
	cache = kmem_cache_create("my_cache", 35, 0, SLAB_HWCACHE_ALIGN, NULL);
	if (NULL == cache) {
		ret = -ENOMEM;
		goto finish;
	}
	printk(KERN_INFO "cache :%p\n", cache);
#if 0
static __always_inline void *kmem_cache_alloc(struct kmem_cache *cachep,
					      gfp_t flags)
#endif
	obj = kmem_cache_alloc(cache, GFP_KERNEL);
	if (NULL == obj) {
		printk(KERN_INFO "kmem_cache_alloc error \n");
		ret = -ENOMEM;
		goto finish;
	}
	printk(KERN_INFO "obj :%p\n", obj);
finish:
	return ret;
}

static void __exit kmem_cache_alloc_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (NULL != obj && NULL != cache) {
#if 0
void kmem_cache_free(struct kmem_cache *cachep, void *objp)
#endif
		kmem_cache_free(cache, obj);
	}
	if (NULL != cache) {
#if 0
void kmem_cache_destroy(struct kmem_cache *cachep)
#endif
		kmem_cache_destroy(cache);
	}
}

module_init(kmem_cache_alloc_init);
module_exit(kmem_cache_alloc_exit);

MODULE_LICENSE("GPL");
