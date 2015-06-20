#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <asm/mman.h>
#include <linux/uaccess.h>

unsigned long addr = 0;
int len = 1000;

static int __init probe_kernel_write_init(void)
{
	unsigned long *src = (unsigned long*)0xdc001234;
	unsigned long *dst = NULL;
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
	*src = 65;
	printk(KERN_INFO "*src :%ld\n", *src);
#if 0
void __sched down_write(struct rw_semaphore *sem)
#endif
	down_write(&current->mm->mmap_sem);
#if 0
unsigned long do_mmap_pgoff(struct file *file, unsigned long addr,
			unsigned long len, unsigned long prot,
			unsigned long flags, unsigned long pgoff)
#endif
	addr = do_mmap_pgoff(NULL, 100, len, PROT_WRITE | PROT_READ,
		MAP_ANONYMOUS | MAP_SHARED, 0);
	if (0xd0000000 < addr) {
		ret = addr;
		printk(KERN_INFO "do_mmap_pgoff error \n");
		goto finish;
	}
	printk(KERN_INFO "addr :%#lx\n", addr);
	up_write(&current->mm->mmap_sem);
	dst = (unsigned long *)addr;
#if 0
long probe_kernel_write(void *dst, void *src, size_t size)
#endif
	ret = probe_kernel_write(dst, src, 4);
	if (0 > ret) {
		ret = -ENOMEM;
		printk(KERN_INFO "probe_kernel_write error\n");
		goto finish;
	}
	printk(KERN_INFO "*dst :%ld\n", *dst);
finish:
	return ret;
}

static void __exit probe_kernel_write_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
#if 0
int do_munmap(struct mm_struct *mm, unsigned long start, size_t len)
#endif
	do_munmap(current->mm, addr, len);
}

module_init(probe_kernel_write_init);
module_exit(probe_kernel_write_exit);

MODULE_LICENSE("GPL");
