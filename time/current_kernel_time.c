#include <linux/init.h>
#include <linux/module.h>
#include <linux/time.h>

static int __init current_kernel_time_init(void)
{
#if 0
struct timespec {
	__kernel_time_t	tv_sec;			/* seconds */
	long		tv_nsec;		/* nanoseconds */
};
#endif
	struct timespec time;
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct timespec current_kernel_time(void)
#endif
	time = current_kernel_time();
	printk(KERN_INFO "time.tv_sec :%ld, time.tv_nsec :%ld\n",
			time.tv_sec, time.tv_nsec);
	return 0;
}

static void __exit current_kernel_time_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(current_kernel_time_init);
module_exit(current_kernel_time_exit);

MODULE_LICENSE("GPL");
