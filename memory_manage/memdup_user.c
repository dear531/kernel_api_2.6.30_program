#include <linux/init.h>
#include <linux/module.h>
#include <linux/sched.h>

static int __init memdup_user_init(void)
{
	struct mm_struct *mm = current->mm;
	char *p = NULL;
	int ret = 0, i;
	printk(KERN_INFO "%s\n", __func__);
#if 0
void *memdup_user(const void __user *src, size_t len)
#endif
	p = memdup_user((void *)mm->mmap->vm_start, 10);
	if (NULL == p) {
		ret = -ENOMEM;
		printk(KERN_INFO "memdup_user error\n");
		goto finish;
	}
	for (i = 0; 10 > i; i++) {
		printk("%d", p[i]);
	}
	printk("\n");
finish:
	return 0;
}

static void __exit memdup_user_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(memdup_user_init);
module_exit(memdup_user_exit);

MODULE_LICENSE("GPL");
