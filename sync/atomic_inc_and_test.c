#include <linux/init.h>
#include <linux/module.h>

static int __init atomic_init(void)
{
	atomic_t v;
	int ret;
	printk(KERN_INFO "%s\n", __func__);
#if 0
#define atomic_set(v,i)		((v)->counter = (i))
#endif
	atomic_set(&v, -5);
#if 0
#define atomic_read(v)		((v)->counter + 0)
#endif
	printk(KERN_INFO "v :%d\n", atomic_read(&v));
#if 0
static __inline__ void atomic_add(int i, atomic_t * v)
#endif
	while (!(ret = atomic_inc_and_test(&v))) {
		printk(KERN_INFO "ret :%d ,v :%d\n",
				ret, atomic_read(&v));
	}
	printk(KERN_INFO "ret :%d ,v :%d\n",
			ret, atomic_read(&v));
	return 0;
}

static void __exit atomic_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(atomic_init);
module_exit(atomic_exit);

MODULE_LICENSE("GPL");
