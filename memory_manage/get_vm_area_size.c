#include <linux/init.h>
#include <linux/module.h>
#include <linux/mm.h>
#include <linux/vmalloc.h>

struct vm_struct *vm = NULL;

static int __init get_vm_area_size_init(void)
{
	size_t size = 8192, actual_size;
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct vm_struct *alloc_vm_area(size_t size)
#endif
	vm = alloc_vm_area(size);
	if (NULL == vm) {
		ret = -ENOMEM;
		goto finish;
	}
#if 0
static inline size_t get_vm_area_size(const struct vm_struct *area)
#endif
	actual_size = get_vm_area_size(vm);
	printk(KERN_INFO "actual_size :%d\n", actual_size);
	printk(KERN_INFO "vm->size :%ld\n", vm->size);
finish:
	return ret;
}

static void __exit get_vm_area_size_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
#if 0
void free_vm_area(struct vm_struct *area)
#endif
	free_vm_area(vm);
}

module_init(get_vm_area_size_init);
module_exit(get_vm_area_size_exit);

MODULE_LICENSE("GPL");
