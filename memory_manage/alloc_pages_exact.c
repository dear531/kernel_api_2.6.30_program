#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/gfp.h>

void *addr = NULL;

static int __init alloc_pages_exact_init(void)
{
	printk(KERN_INFO "%s\n", __func__);
#if 0
void *alloc_pages_exact(size_t size, gfp_t gfp_mask)
#endif
	addr = alloc_pages_exact(100, GFP_KERNEL);
	if (NULL == addr) {
		return -ENOMEM;
	}
	printk(KERN_INFO "addr :%p\n", addr);
	return 0;
}

static void __exit alloc_pages_exact_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (NULL != addr) {
#if 0
void free_pages_exact(void *virt, size_t size)
#endif
		free_pages_exact(addr, 100);
	}
}

module_init(alloc_pages_exact_init);
module_exit(alloc_pages_exact_exit);

MODULE_LICENSE("GPL");
