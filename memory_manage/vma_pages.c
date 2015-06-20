#include <linux/init.h>
#include <linux/module.h>
#include <linux/mman.h>
#include <linux/mm.h>
#include <linux/sched.h>

static int __init vma_pages_init(void)
{
	struct vm_area_struct *vma = NULL;
	unsigned long addr;
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr)
#endif
	vma = find_vma(current->mm, current->mm->mmap->vm_start + 1);
	if (NULL == vma) {
		printk(KERN_INFO "not found vm\n");
		goto finish;
	}
#if 0
static inline unsigned long vma_pages(struct vm_area_struct *vma)
#endif
	addr = vma_pages(vma);
	printk(KERN_INFO "addr :%#lx\n", addr);
finish:
	return 0;
}

static void __exit vma_pages_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(vma_pages_init);
module_exit(vma_pages_exit);

MODULE_LICENSE("GPL");
