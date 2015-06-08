#include <linux/init.h>
#include <linux/module.h>

static int __init kstrdup_init(void)
{
	const char *p = "hello world";
	char *new = NULL;
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
char *kstrdup(const char *s, gfp_t gfp)
#endif
	new = kstrdup(p, GFP_KERNEL);
	if (NULL == new) {
		ret = -ENOMEM;
		printk(KERN_INFO "kstrdup error\n");
		goto finish;
	}
	printk(KERN_INFO "new :%s\n", new);
finish:
	return ret;
}

static void __exit kstrdup_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(kstrdup_init);
module_exit(kstrdup_exit);

MODULE_LICENSE("GPL");
