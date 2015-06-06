#include <linux/init.h>
#include <linux/module.h>
#include <linux/mm.h>
#include <linux/sched.h>

static int __init get_user_pages_fast_init(void)
{
	struct page *pages = NULL;
	int ret, len;
	printk(KERN_INFO "%s\n", __func__);
#if 0
int get_user_pages_fast(unsigned long start, int nr_pages, int write,
			struct page **pages)
#endif
	len = vma_pages(current->mm->mmap);
	printk(KERN_INFO "len :%d\n", len);
	ret = get_user_pages_fast(current->mm->mmap->vm_start,
			len, 0, &pages);
	if (0 > ret) {
		printk(KERN_INFO "get_user_pages_fast result :%d\n", ret);
	}
	printk(KERN_INFO "pages :%#lx\n", pages);
	return 0;
}

static void __exit get_user_pages_fast_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(get_user_pages_fast_init);
module_exit(get_user_pages_fast_exit);

MODULE_LICENSE("GPL");
