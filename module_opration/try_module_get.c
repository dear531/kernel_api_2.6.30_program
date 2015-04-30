#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int module_get_ret;

static int __init try_module_get_init(void)
{
	printk(KERN_INFO "try_module_get_init\n");
	printk(KERN_INFO "befor try_module_get :%d\n",
			module_refcount(THIS_MODULE));
	module_get_ret = try_module_get(THIS_MODULE);
	printk(KERN_INFO "module_get_ret :%d\n",
			module_get_ret);
	printk(KERN_INFO "after try_module_get :%d\n",
			module_refcount(THIS_MODULE));
	if (0 != module_get_ret) {
		/* note: module_put must in init function,
		 * invalid for sometime rmmod and decment
		 * in exit function
		 */
		module_put(THIS_MODULE);
		printk(KERN_INFO "after module_put :%d\n",
				module_refcount(THIS_MODULE));
	}
	return 0;
}

static void __exit try_module_get_exit(void)
{
	printk(KERN_INFO "try_module_get_exit\n");
}

module_init(try_module_get_init);
module_exit(try_module_get_exit);

MODULE_LICENSE("GPL");
