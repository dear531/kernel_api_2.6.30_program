#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/uaccess.h>

static int __init probe_kernel_address_init(void)
{
	struct mm_struct *mm = current->mm;
	long *addr = (long *)mm->mmap->vm_start;
	long retval = 0;
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
	printk(KERN_INFO "vm_start value :%ld\n", *addr);
	ret = probe_kernel_address(addr, retval);
	printk(KERN_INFO "ret :%d\n", ret);
	printk(KERN_INFO "retval :%ld\n", retval);
	return 0;
}

static void __exit probe_kernel_address_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(probe_kernel_address_init);
module_exit(probe_kernel_address_exit);

MODULE_LICENSE("GPL");
