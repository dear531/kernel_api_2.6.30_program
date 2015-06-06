#include <linux/init.h>
#include <linux/module.h>
#include <linux/mman.h>

static int __init get_unmapped_area_init(void)
{
	unsigned long addr = 100, len = 1025;
	printk(KERN_INFO "%s\n", __func__);
#if 0
unsigned long get_unmapped_area(struct file *file, unsigned long addr,
				unsigned long len, unsigned long pgoff,
				unsigned long flags)
#endif
	addr = get_unmapped_area(NULL, addr, len, 0, MAP_ANONYMOUS);
	if (0xc0000000 < addr) {
		printk(KERN_INFO "get_unmapped_area failed\n");
		goto finish;
	}
	printk(KERN_INFO "addr :%#lx\n", addr);
finish:
	return 0;
}

static void __exit get_unmapped_area_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(get_unmapped_area_init);
module_exit(get_unmapped_area_exit);

MODULE_LICENSE("GPL");
