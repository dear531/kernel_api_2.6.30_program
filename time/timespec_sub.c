#include <linux/init.h>
#include <linux/module.h>

static int __init timespec_sub_init(void)
{
	struct timespec
		ts1 = {.tv_sec = 3, .tv_nsec = 3,},
		ts2 = {.tv_sec = 2, .tv_nsec = 2,}, ts3;
	printk(KERN_INFO "%s\n", __func__);
#if 0
static inline struct timespec timespec_sub(struct timespec lhs,
						struct timespec rhs)
#endif
	ts3 = timespec_sub(ts1, ts2);
	printk(KERN_INFO "ts3.tv_sec :%ld, ts3.tv_nsec :%ld\n",
			ts3.tv_sec, ts3.tv_nsec);
	return 0;
}

static void __exit timespec_sub_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(timespec_sub_init);
module_exit(timespec_sub_exit);

MODULE_LICENSE("GPL");
