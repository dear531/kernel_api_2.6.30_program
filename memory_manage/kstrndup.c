#include <linux/init.h>
#include <linux/module.h>

static int __init kstrndup_init(void)
{
	const char *s = "12345";
	char *p = NULL;
	printk(KERN_INFO "%s\n", __func__);
#if 0
char *kstrndup(const char *s, size_t max, gfp_t gfp)
#endif
	p = kstrndup(s, strlen(s) - 1, GFP_KERNEL);
	printk(KERN_INFO "s :%s, p :%s\n", s, p);
	return 0;
}

static void __exit kstrndup_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(kstrndup_init);
module_exit(kstrndup_exit);

MODULE_LICENSE("GPL");
