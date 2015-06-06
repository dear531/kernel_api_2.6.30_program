#include <linux/init.h>
#include <linux/module.h>
#include <linux/gfp.h>

unsigned long addr = 0;
static int __init get_zeroed_page_init(void)
{
	int ret = 0;
	char *p;
	printk(KERN_INFO "%s\n", __func__);
#if 0
unsigned long get_zeroed_page(gfp_t gfp_mask)
#endif
	addr = get_zeroed_page(GFP_KERNEL);
	if (0 == addr) {
		printk(KERN_INFO "get_zeroed_page error \n");
		ret = -ENOMEM;
	}
	printk(KERN_INFO "addr :%#lx\n", addr);
	p = (char *)addr;
	printk(KERN_INFO "p[1] :%d, p[10] :%d\n", p[1],
			p[10]);
	return ret;
}

static void __exit get_zeroed_page_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	if (0 != addr) {
		free_page(addr);
	}
}

module_init(get_zeroed_page_init);
module_exit(get_zeroed_page_exit);

MODULE_LICENSE("GPL");
