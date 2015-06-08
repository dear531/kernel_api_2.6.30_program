#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>

struct kmem_cache *cache = NULL;
void *p = NULL, *p2 = NULL;

static int ksize_init(void)
{
	int size, size2;
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct kmem_cache *
kmem_cache_create (const char *name, size_t size, size_t align,
	unsigned long flags, void (*ctor)(void *))
#endif
	cache = kmem_cache_create("mycache", 29, 0, SLAB_HWCACHE_ALIGN, NULL);
	if (NULL == cache) {
		ret = -ENOMEM;
		printk(KERN_INFO "kmem_cache_create error \n");
		goto finish;
	}
#if 0
static __always_inline void *kmem_cache_alloc(struct kmem_cache *cachep,
					      gfp_t flags)
#endif
	p = kmem_cache_alloc(cache, GFP_KERNEL);
	if (NULL == p) {
		ret = -ENOMEM;
		printk(KERN_INFO "kmem_cache_alloc error\n");
		goto finish;
	}
	size = ksize(p);
	printk(KERN_INFO "p size :%d\n", size);
#if 0
static __always_inline void *kmalloc(size_t size, gfp_t flags)
#endif
	p2 = kmalloc(8080, GFP_KERNEL);
	if (NULL == p2) {
		ret = -ENOMEM;
		printk(KERN_INFO "kmalloc error \n");
		goto finish;
	}
	size2 = ksize(p2);
	printk(KERN_INFO "p2 size2 :%d\n", size2);
finish:
	return ret;
}

static void ksize_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (NULL != p) {
#if 0
void kmem_cache_free(struct kmem_cache *cachep, void *objp)
#endif
		kmem_cache_free(cache, p);
		p = NULL;
	}
	if (NULL != cache) {
#if 0
void kmem_cache_destroy(struct kmem_cache *cachep)
#endif
		kmem_cache_destroy(cache);
		cache = NULL;
	}
	if (NULL != p2) {
#if 0
void kfree(const void *objp)
#endif
		kfree(p2);
		p2 = NULL;
	}
}

module_init(ksize_init);
module_exit(ksize_exit);

MODULE_LICENSE("GPL");
