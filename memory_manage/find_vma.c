#include <linux/init.h>
#include <linux/module.h>
#include <linux/mm_types.h>
#include <linux/mm.h>
#include <linux/sched.h>

static int __init find_vma_init(void)
{
	unsigned long addr;
	struct vm_area_struct *vm;
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
	addr = current->mm->mmap->vm_next->vm_start + 1;
	printk(KERN_INFO "addr :%#lx\n", addr);
#if 0
struct vm_area_struct *find_vma(struct mm_struct *mm, unsigned long addr)
#endif
	vm = find_vma(current->mm, addr);
	if (NULL == vm) {
		ret = -ENOMEM;
		goto finish;
	}
	printk(KERN_INFO "vm->sart :%#lx, vm->vm_end :%#lx\n",
			vm->vm_start, vm->vm_end);
finish:
	return ret;
}

static void __exit find_vma_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(find_vma_init);
module_exit(find_vma_exit);

MODULE_LICENSE("GPL");
