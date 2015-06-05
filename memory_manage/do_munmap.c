#include <linux/init.h>
#include <linux/module.h>
#include <linux/mm.h>
#include <linux/sched.h>
#include <linux/mman.h>

#define define_nobrt	0

static int __init do_munmap_init(void)
{
	size_t len = 4096;
	unsigned long addr = 100;
	int ret;
	printk(KERN_INFO "%s\n", __func__);
	if (!define_nobrt) {
#if 0
static inline unsigned long do_mmap(struct file *file, unsigned long addr,
	unsigned long len, unsigned long prot,
	unsigned long flag, unsigned long offset)
#endif
		down_write(&current->mm->mmap_sem);
		addr = do_mmap(NULL, addr, len, PROT_READ | PROT_WRITE,
				MAP_SHARED | MAP_ANONYMOUS, 0);
		up_write(&current->mm->mmap_sem);
	}
#if 0
void __sched down_write(struct rw_semaphore *sem)
#endif
	printk(KERN_INFO "after do_munmap mm->mm_count :%d\n",
			current->mm->mm_count);
	down_write(&current->mm->mmap_sem);
	if (define_nobrt) {
#if 0
int do_munmap(struct mm_struct *mm, unsigned long start, size_t len)
#endif
		ret = do_munmap(current->mm, current->mm->mmap->vm_start, len);
		goto finish;
	} else {
		ret = do_munmap(current->mm, addr, len);
	}
	printk(KERN_INFO "ret :%d\n", ret);
finish:
	up_write(&current->mm->mmap_sem);
	printk(KERN_INFO "befor do_munmap mm->mm_count :%d\n",
			current->mm->mm_count);
	return 0;
}

static void __exit do_munmap_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(do_munmap_init);
module_exit(do_munmap_exit);

MODULE_LICENSE("GPL");
