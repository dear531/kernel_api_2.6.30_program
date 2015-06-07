#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>

char (*array)[2][10];

static int __init kmalloc_init(void)
{
	int i, j;
	printk(KERN_INFO "%s\n", __func__);
#if 0
static __always_inline void *kmalloc(size_t size, gfp_t flags)
#endif
	array = kmalloc(sizeof(*array), GFP_KERNEL);
	for (i = 0; sizeof(*array) / sizeof(**array) > i; i++) {
		for (j = 0; sizeof(**array) / sizeof(***array) > j; j++) {
			printk("%c", *array[i][j]);
		}
		printk("\n");
	}
	return 0;
}

static void __exit kmalloc_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (NULL != array)
		kfree(array);
}

module_init(kmalloc_init);
module_exit(kmalloc_exit);

MODULE_LICENSE("GPL");
