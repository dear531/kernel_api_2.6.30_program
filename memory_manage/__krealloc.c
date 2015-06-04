#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/slab.h>

struct page *addr = NULL;
size_t new_size = 26;

static int __init __krealloc_init(void)
{
	int i;
	char *p;
	printk(KERN_INFO "%s\n", __func__);
	addr = alloc_pages(GFP_KERNEL, 0);
	if (NULL == addr) {
		return -ENOMEM;
	}
	printk(KERN_INFO "addr :%p\n", addr);
	p = (char *)addr;
	for (i = 0; new_size > i; i++) {
		p[i] = 'a' + i;
		printk("%c", p[i]);
	}
	printk("\n");
#if 0
void *krealloc(const void *p, size_t new_size, gfp_t flags)
#endif
	p = __krealloc(addr, new_size, GFP_KERNEL);
#if 0

	if (NULL == p) {
		return -ENOMEM;
	}

	printk(KERN_INFO "p:%p\n", p);

	for (i = 0; new_size > i; i++) {
		printk("%c", p[i]);
	}
	printk(KERN_INFO "\n");
#endif

	return 0;
}

static void __exit __krealloc_exit (void)
{
	printk(KERN_INFO "%s\n", __func__);
	__free_pages(addr, 0);
}
module_init(__krealloc_init);
module_exit(__krealloc_exit);

MODULE_LICENSE("GPL");
