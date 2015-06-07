#include <linux/init.h>
#include <linux/module.h>
#include <linux/slab.h>

char (*array)[2][10];

static int __init kcalloc_init(void)
{
	int ret = 0, i, j;
	printk(KERN_INFO "%s\n", __func__);
#if 0
static inline void *kcalloc(size_t n, size_t size, gfp_t flags)
#endif
	array = kcalloc(2, sizeof(**array), GFP_KERNEL);
	if (NULL == array) {
		ret = -ENOMEM;
	}
	printk(KERN_INFO "array :%d, *array :%d, **array :%d, ***array :%d\n",
		sizeof(array), sizeof(*array),
		sizeof (**array), sizeof(***array));
	for (i = 0; sizeof(*array) / sizeof(**array) > i; i++) {
		for (j = 0; sizeof(**array) / sizeof(***array) > j; j++) {
			printk("%d", *(array[i][j]));
		}
		printk(KERN_INFO "\n");
	}
	return ret;
}

static void __exit kcalloc_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (NULL != array) {
		kfree(array);
	}
}

module_init(kcalloc_init);
module_exit(kcalloc_exit);

MODULE_LICENSE("GPL");
