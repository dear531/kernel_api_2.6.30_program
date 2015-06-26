#include <linux/init.h>
#include <linux/module.h>

static int __init getnstimeofday_init(void)
{
	struct timespec tv = {0};
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct timespec {
	__kernel_time_t	tv_sec;			/* seconds */
	long		tv_nsec;		/* nanoseconds */
};
void getnstimeofday(struct timespec *tv)
#endif
	getnstimeofday(&tv);
	printk(KERN_INFO "tv.tv_sec :%ld, tv.tv_nsec %ld\n",
			tv.tv_sec, tv.tv_nsec);
	return 0;
}

static void __exit getnstimeofday_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(getnstimeofday_init);
module_exit(getnstimeofday_exit);

MODULE_LICENSE("GPL");
