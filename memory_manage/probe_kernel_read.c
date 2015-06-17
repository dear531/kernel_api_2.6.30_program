#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/uaccess.h>

static int __init probe_kernel_read_init(void)
{
	long *dst = (long *)0xd0001234;
	struct mm_struct *mm = current->mm;
	long *src = (long *)mm->mmap->vm_start;
	printk(KERN_INFO "%s\n", __func__);
	printk(KERN_INFO "mv_start :%ld\n", *src);
#if 0
long probe_kernel_read(void *dst, void *src, size_t size)
#endif
	probe_kernel_read(dst, src, 4);
	printk(KERN_INFO "dst :%ld\n", *dst);
	return 0;
}

static void __exit probe_kernel_read_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(probe_kernel_read_init);
module_exit(probe_kernel_read_exit);

MODULE_LICENSE("GPL");
