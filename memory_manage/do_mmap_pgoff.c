#include <linux/init.h>
#include <linux/module.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/mman.h>

unsigned long addr = 100, len = 1000;

static int __init do_mmap_pgoff_init(void)
{
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
void __sched down_write(struct rw_semaphore *sem)
#endif
	printk(KERN_INFO "after do_mmap_pgoff mm_count :%d\n",
			current->mm->mm_count);
	down_write(&current->mm->mmap_sem);
#if 0
unsigned long do_mmap_pgoff(struct file *file, unsigned long addr,
			unsigned long len, unsigned long prot,
			unsigned long flags, unsigned long pgoff)
#endif
	addr = do_mmap_pgoff(NULL, addr, len, PROT_READ | PROT_WRITE,
			MAP_SHARED | MAP_ANONYMOUS, 0);
	printk(KERN_INFO "addr :%#lx\n", addr);
	if (0xc0000000 < addr) {
		ret = -ENOMEM;
		printk(KERN_INFO "do_mmap_pgoff error\n");
	}
	up_write(&current->mm->mmap_sem);
	printk(KERN_INFO "befor do_mmap_pgoff mm_count :%d\n",
			current->mm->mm_count);
	return ret;
}

static void __exit do_mmap_pgoff_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	down_write(&current->mm->mmap_sem);
#if 0
int do_munmap(struct mm_struct *mm, unsigned long start, size_t len)
#endif
	do_munmap(current->mm, addr, len);
	up_write(&current->mm->mmap_sem);
}

module_init(do_mmap_pgoff_init);
module_exit(do_mmap_pgoff_exit);

MODULE_LICENSE("GPL");
