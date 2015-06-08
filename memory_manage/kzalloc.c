#include <linux/init.h>
#include <linux/module.h>

static int __init kzalloc_init(void)
{
	char *p = NULL;
	int ret = 0, i;
	printk(KERN_INFO "%s\n", __func__);
#if 0
static inline void *kzalloc(size_t size, gfp_t flags)
#endif
	p = kzalloc(10, GFP_KERNEL);
	if (NULL == p) {
		ret = -ENOMEM;
		printk(KERN_INFO "kzalloc error \n");
		goto finish;
	}
	for (i = 0; 10 > i; i++) {
		printk("%d", p[i]);
	}
	printk("\n");
finish:
	return ret;
}

static void __exit kzalloc_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(kzalloc_init);
module_exit(kzalloc_exit);

MODULE_LICENSE("GPL");
