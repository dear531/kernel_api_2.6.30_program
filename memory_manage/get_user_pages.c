#include <linux/init.h>
#include <linux/module.h>
#include <linux/mm.h>
#include <linux/sched.h>

static int __init get_user_pages_init(void)
{
	int len;
	struct page *pages;
	int ret = 0;
	printk(KERN_INFO "%s\n", __func__);
	
#if 0
static inline unsigned long vma_pages(struct vm_area_struct *vma)
#endif
	len = vma_pages(current->mm->mmap);
	down_read(&current->mm->mmap_sem);
#if 0
int get_user_pages(struct task_struct *tsk, struct mm_struct *mm,
		unsigned long start, int len, int write, int force,
		struct page **pages, struct vm_area_struct **vmas)
#endif
	ret = get_user_pages(current, current->mm, current->mm->mmap->vm_start, len, 0, 0, &pages,
			NULL);
	if (0 > ret) {
		printk(KERN_INFO "get_user_pages error \n");
	}

	up_read(&current->mm->mmap_sem);
	printk(KERN_INFO "pages :%#p\n", pages);
#if 0
static inline int page_count(struct page *page)
#endif
	printk(KERN_INFO "page_count :%d\n", page_count(pages));

	return 0;
}

static void __exit get_user_pages_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(get_user_pages_init);
module_exit(get_user_pages_exit);

MODULE_LICENSE("GPL");
