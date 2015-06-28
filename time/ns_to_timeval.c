#include <linux/init.h>
#include <linux/module.h>

static int __init ns_to_timeval_init(void)
{
	struct timeval tv0, tv1;
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct timeval ns_to_timeval(const s64 nsec)
struct timeval {
	__kernel_time_t		tv_sec;		/* seconds */
	__kernel_suseconds_t	tv_usec;	/* microseconds */
};
#endif
	tv0 = ns_to_timeval(0);
	printk(KERN_INFO "tv0.tv_sec :%ld, tv0.tv_usec :%ld\n",
			tv0.tv_sec, tv0.tv_usec);
	tv1 = ns_to_timeval(1000 * 1000 * 1000 + 1000 * 1000);
	printk(KERN_INFO "tv1.tv_sec :%ld, tv1.tv_usec :%ld\n",
			tv1.tv_sec, tv1.tv_usec);
	return 0;
}

static void __exit ns_to_timeval_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(ns_to_timeval_init);
module_exit(ns_to_timeval_exit);

MODULE_LICENSE("GPL");
