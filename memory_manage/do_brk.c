#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/mm.h>
#include <linux/sched.h>

unsigned long addr = 200, len = 8192;

static int __init do_brk_init(void)
{
	struct mm_struct *mm = current->mm;
	printk(KERN_INFO "%s\n", __func__);
	printk(KERN_INFO "after do_brk mm->mm_count :%d\n", mm->mm_count);
	down_write(&current->mm->mmap_sem);
#if 0
unsigned long do_brk(unsigned long addr, unsigned long len)
#endif
	addr = do_brk(addr, len);
	if (0x80000000 < addr) {
		printk(KERN_INFO "do_brk error \n");
	}
	up_write(&current->mm->mmap_sem);
	printk(KERN_INFO "init mm addr :%p\n", current->mm);
	printk(KERN_INFO "current->pid :%d\n", current->pid);
	printk(KERN_INFO "addr :%#lx\n", addr);
	printk(KERN_INFO "befor do_brk mm->mm_count :%d\n", mm->mm_count);
	return 0;
}

static void __exit do_brk_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	down_write(&current->mm->mmap_sem);
#if 0
int do_munmap(struct mm_struct *mm, unsigned long start, size_t len)
#endif
	do_munmap(current->mm, addr, len);
	printk(KERN_INFO "exit mm addr :%p\n", current->mm);
	up_write(&current->mm->mmap_sem);
	printk(KERN_INFO "current->pid :%d\n", current->pid);
}

module_init(do_brk_init);
module_exit(do_brk_exit);

MODULE_LICENSE("GPL");
