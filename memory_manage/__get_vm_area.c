#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/vmalloc.h>

struct vm_struct *vm_addr;

static int __init __get_vm_area_init(void)
{
	printk(KERN_INFO "%s\n", __func__);
#if 0
struct vm_struct *__get_vm_area(unsigned long size, unsigned long flags,
				unsigned long start, unsigned long end)
#endif
	vm_addr = __get_vm_area(8192 * 4, VM_ALLOC, 0xc0000100, 0xdd000000);
	if (NULL != vm_addr) {
		printk(KERN_INFO "vm_addr :%p\n", vm_addr);
		printk(KERN_INFO "vm_addr->size :%ld, vm_addr->addr:%p\n",
				vm_addr->size, vm_addr->addr);
	} else {
		printk(KERN_INFO "__get_vm_area %p\n", vm_addr);
	}
	return 0;
}

static void __exit __get_vm_area_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	free_vm_area(vm_addr);
}

module_init(__get_vm_area_init);
module_exit(__get_vm_area_exit);

MODULE_LICENSE("GPL");
