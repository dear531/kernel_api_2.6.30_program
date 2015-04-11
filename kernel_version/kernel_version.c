#include <linux/module.h>
#include <linux/init.h>
#include <linux/version.h>

int kernel_version_init(void)
{
#if 1
	printk(KERN_ALERT "kernel_version(3.2.0):%d\n",
			KERNEL_VERSION(3,2,0));
#ifdef UST_RELEASE
	printk(kern_alert "UST_RELEASE",
			UST_RELEASE);
#endif
	printk(KERN_ALERT "kernel_version(2.6.30):%d\n",
			KERNEL_VERSION(2,6,30));
	printk(KERN_ALERT "LINUX_VERSION_CODE:%d\n",
			LINUX_VERSION_CODE);
#endif
	return 0;
}
void kernel_version_exit(void)
{
	printk(KERN_ALERT "kernel_version exit\n");
}

module_init(kernel_version_init);
module_exit(kernel_version_exit);

MODULE_LICENSE("GPL");
