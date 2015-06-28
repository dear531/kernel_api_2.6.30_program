#include <linux/init.h>
#include <linux/module.h>

static int __init set_normalized_timespec_init(void)
{
	struct timespec tv = {0};
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct timespec {
	__kernel_time_t	tv_sec;			/* seconds */
	long		tv_nsec;		/* nanoseconds */
};
void set_normalized_timespec(struct timespec *ts, time_t sec, long nsec)
#endif
	printk(KERN_INFO "befor set_normalized_timespec tv.tv_sec :%ld, tv.tv_nsec :%ld\n",
			tv.tv_sec, tv.tv_nsec);
	set_normalized_timespec(&tv, 10, 20);
	printk(KERN_INFO "after set_normalized_timespec tv.tv_sec :%ld, tv.tv_nsec :%ld\n",
			tv.tv_sec, tv.tv_nsec);
	return 0;
}

static void __exit set_normalized_timespec_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(set_normalized_timespec_init);
module_exit(set_normalized_timespec_exit);

MODULE_LICENSE("GPL");
