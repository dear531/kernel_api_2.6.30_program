#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/vmalloc.h>

struct vm_struct *vm = NULL;

static int __init alloc_vm_area_init(void)
{
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct vm_struct {
	struct vm_struct	*next;
	void			*addr;
	unsigned long		size;
	unsigned long		flags;
	struct page		**pages;
	unsigned int		nr_pages;
	unsigned long		phys_addr;
	void			*caller;
struct vm_struct *alloc_vm_area(size_t size)
#endif
	vm = alloc_vm_area(10);
	if (NULL == vm) {
		return -ENOMEM;
	}
	printk(KERN_INFO "vm->addr :%p\n", vm->addr);
	printk(KERN_INFO "vm->phys_addr :%#lx\n", vm->phys_addr);
	printk(KERN_INFO "vm->size :%ld, vm->nr_pages :%d\n",
			vm->size, vm->nr_pages);

	return 0;
}

static void __exit alloc_vm_area_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
#if 0
void free_vm_area(struct vm_struct *area)
#endif
	if (NULL != vm) {
		free_vm_area(vm);
	}
}

module_init(alloc_vm_area_init);
module_exit(alloc_vm_area_exit);

MODULE_LICENSE("GPL");
