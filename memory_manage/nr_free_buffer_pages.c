#include <linux/init.h>
#include <linux/module.h>
#include <linux/swap.h>

static int __init nr_free_buffer_pages_init(void)
{
	int nr;
	printk(KERN_INFO "%s\n", __func__);
#if 0
unsigned int nr_free_buffer_pages(void)
#endif
	nr = nr_free_buffer_pages();
	printk(KERN_INFO "nr :%d\n", nr);
	return 0;
}

static void __exit nr_free_buffer_pages_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(nr_free_buffer_pages_init);
module_exit(nr_free_buffer_pages_exit);

MODULE_LICENSE("GPL");
