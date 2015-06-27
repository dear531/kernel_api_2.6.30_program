#include <linux/init.h>
#include <linux/module.h>

static int __init mktime_init(void)
{
	unsigned long time0, time1;
	printk(KERN_INFO "%s\n", __func__);
#if 0
unsigned long
mktime(const unsigned int year0, const unsigned int mon0,
       const unsigned int day, const unsigned int hour,
       const unsigned int min, const unsigned int sec)
#endif
	time0 = mktime(1970, 1, 1, 0, 0, 0);
	time1 = mktime(2015, 6, 27, 12, 16, 51);
	printk(KERN_INFO "time0 :%ld, time1 :%ld\n",
			time0, time1);
	return 0;
}

static void __exit mktime_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(mktime_init);
module_exit(mktime_exit);

MODULE_LICENSE("GPL");
