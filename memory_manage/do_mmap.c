#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/mm.h>
#include <linux/mman.h>

unsigned long addr, len = 1000;

static int __init do_mmap_init(void)
{
	printk(KERN_INFO "%s\n", __func__);
	printk(KERN_INFO "after do_mmap mm_count :%d\n",
			current->mm->mm_count);
#if 0
void __sched down_write(struct rw_semaphore *sem)
#endif
	down_write(&current->mm->mmap_sem);
#if 0
static inline unsigned long do_mmap(struct file *file, unsigned long addr,
	unsigned long len, unsigned long prot,
	unsigned long flag, unsigned long offset)
#endif
	addr = do_mmap(NULL, 100, len, PROT_READ | PROT_WRITE,
			MAP_ANONYMOUS | MAP_SHARED, 0);
	up_write(&current->mm->mmap_sem);
	printk(KERN_INFO "after do_mmap mm_count :%d\n",
			current->mm->mm_count);
	if (0xc0000000 < addr) {
		printk(KERN_INFO "do_mmap error addr %#lx\n", addr);
	}
	return 0;
}

static void __exit do_mmap_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (addr > 0x80000000) {
		return;
	}
#if 0
void __sched down_write(struct rw_semaphore *sem)
#endif
	down_write(&current->mm->mmap_sem);
#if 0
int do_munmap(struct mm_struct *mm, unsigned long start, size_t len)
#endif
	do_munmap(current->mm, addr, len);
	up_write(&current->mm->mmap_sem);
}

module_init(do_mmap_init);
module_exit(do_mmap_exit);

MODULE_LICENSE("GPL");
