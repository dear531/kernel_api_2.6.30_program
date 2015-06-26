#include <linux/init.h>
#include <linux/module.h>

static int __init do_gettimeofday_init(void)
{
	struct timeval tv = {0};
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct timeval {
	__kernel_time_t		tv_sec;		/* seconds */
	__kernel_suseconds_t	tv_usec;	/* microseconds */
};
void
do_gettimeofday(struct timeval *tv)
#endif
	printk(KERN_INFO "befor do_gettimeofday tv.tv_sec :%d, tv.tv_usec :%d\n",
			tv.tv_sec, tv.tv_usec);
	do_gettimeofday(&tv);
	printk(KERN_INFO "after do_gettimeofday tv.tv_sec :%d, tv.tv_usec :%d\n",
			tv.tv_sec, tv.tv_usec);
	return 0;
}

static void __exit do_gettimeofday_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(do_gettimeofday_init);
module_exit(do_gettimeofday_exit);

MODULE_LICENSE("GPL");
