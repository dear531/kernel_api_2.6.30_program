#include <linux/init.h>
#include <linux/module.h>

static int __init timespec_to_ns_init(void)
{
	struct timespec ts = {1, 1};
	unsigned long ns;
	printk(KERN_INFO "%s\n", __func__);
#if 0
static inline s64 timespec_to_ns(const struct timespec *ts)
#endif
	ns = timespec_to_ns(&ts);
	printk(KERN_INFO "ns :%ld\n", ns);

	return 0;
}

static void __exit timespec_to_ns_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(timespec_to_ns_init);
module_exit(timespec_to_ns_exit);

MODULE_LICENSE("GPL");
