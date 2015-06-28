#include <linux/init.h>
#include <linux/module.h>

static int __init timespec_compare_init(void)
{
	int ret;
	struct timespec lhs = {0}, rhs = {1};
	printk(KERN_INFO "%s\n", __func__);
#if 0
static inline int timespec_compare(const struct timespec *lhs, const struct timespec *rhs)
#endif
	ret = timespec_compare(&lhs, &lhs);
	printk(KERN_INFO "compare 0 and 0 result :%d\n", ret);
	ret = timespec_compare(&rhs, &lhs);
	printk(KERN_INFO "compare 1 and 0 result :%d\n", ret);
	ret = timespec_compare(&lhs, &rhs);
	printk(KERN_INFO "compare 0 and 1 result :%d\n", ret);
	return 0;
}

static void __exit timespec_compare_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(timespec_compare_init);
module_exit(timespec_compare_exit);

MODULE_LICENSE("GPL");
