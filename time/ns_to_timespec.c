#include <linux/init.h>
#include <linux/module.h>

static int __init ns_to_timespec_init(void)
{
	struct timespec tn0, tn1;
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct timespec ns_to_timespec(const s64 nsec)
struct timespec {
        long       tv_sec;
        long       tv_nsec;
};
#endif
	tn0 = ns_to_timespec(0);
	printk(KERN_INFO "tn0.tv_sec :%ld, tn0.tv_nsec :%ld\n",
			tn0.tv_sec, tn0.tv_nsec);
	tn1 = ns_to_timespec(1000 * 1000 * 1000 + 1000);
	printk(KERN_INFO "tn1.tv_sec :%ld, tn1.tv_nsec :%ld\n",
			tn1.tv_sec, tn1.tv_nsec);
	return 0;
}

static void __exit ns_to_timespec_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(ns_to_timespec_init);
module_exit(ns_to_timespec_exit);

MODULE_LICENSE("GPL");
