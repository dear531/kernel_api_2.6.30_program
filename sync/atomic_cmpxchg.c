#include <linux/init.h>
#include <linux/module.h>

static int __init atomic_init(void)
{
	atomic_t v;
	int ret, old, new;
	printk(KERN_INFO "%s\n", __func__);
#if 0
#define atomic_set(v,i)		((v)->counter = (i))
#endif
	atomic_set(&v, 4);
#if 0
#define atomic_read(v)		((v)->counter + 0)
#endif
	printk(KERN_INFO "v :%d\n", atomic_read(&v));
#if 0
#define atomic_cmpxchg(v, old, new) (cmpxchg(&((v)->counter), old, new))
#endif
	old = 4;
	new = 5;
	ret = atomic_cmpxchg(&v, old, new);
	printk(KERN_INFO "old :%d, new :%d ,ret :%d, v :%d\n",
			old, new, ret, atomic_read(&v));

	old = 3;
	new = 2;
	ret = atomic_cmpxchg(&v, 3, 2);
	printk(KERN_INFO "old :%d, new :%d ,ret :%d, v :%d\n",
			old, new, ret, atomic_read(&v));
	return 0;
}

static void __exit atomic_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(atomic_init);
module_exit(atomic_exit);

MODULE_LICENSE("GPL");
