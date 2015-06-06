#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>
#include <linux/mm.h>

static int __init find_vma_intersection_init(void)
{
	struct mm_struct *mm = current->mm;
	struct vm_area_struct *vm;
	unsigned long start_addr, end_addr;
	printk(KERN_INFO "%s\n", __func__);
#if 0
static inline struct vm_area_struct * find_vma_intersection(struct mm_struct * mm, unsigned long start_addr, unsigned long end_addr)
#endif
	start_addr = current->mm->mmap->vm_start + 1;
	end_addr = current->mm->mmap->vm_end + 1;
	vm = find_vma_intersection(mm, start_addr, end_addr);
	if (NULL == vm) {
		printk(KERN_INFO "start %#lx end %#lx is not exists\n",
				start_addr, end_addr);
	} else {
		printk(KERN_INFO "vm->vm_start :%#lx\n", vm->vm_start);
	}

	start_addr = current->mm->mmap->vm_start - 10;
	end_addr = current->mm->mmap->vm_end - 1;
	vm = find_vma_intersection(mm, start_addr, end_addr);
	if (NULL == vm) {
		printk(KERN_INFO "start %#lx end %#lx is not exists\n",
				start_addr, end_addr);
	} else {
		printk(KERN_INFO "vm->vm_start :%#lx\n", vm->vm_start);
	}
	return 0;
}

static void __exit find_vma_intersection_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(find_vma_intersection_init);
module_exit(find_vma_intersection_exit);

MODULE_LICENSE("GPL");
