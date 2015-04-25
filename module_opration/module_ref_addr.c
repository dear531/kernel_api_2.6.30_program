#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>

static int __init module_ref_addr_init(void)
{
	unsigned int cpuid;
	local_t *l;
	cpuid = get_cpu();
	l = __module_ref_addr(THIS_MODULE, cpuid);
	printk(KERN_INFO "address :%lx\n", (unsigned long)l);
	printk(KERN_INFO "count :%d\n", module_refcount(THIS_MODULE));
	local_inc(l);
	printk(KERN_INFO "count :%d\n", module_refcount(THIS_MODULE));
	local_dec(l);
	printk(KERN_INFO "count :%d\n", module_refcount(THIS_MODULE));
	printk(KERN_INFO "module_ref_addr init\n");
	put_cpu();
	return 0;
}

static void __exit module_ref_addr_exit(void)
{
	printk(KERN_INFO "module_ref_add exit\n");
}

module_init(module_ref_addr_init);
module_exit(module_ref_addr_exit);

MODULE_LICENSE("GPL");
