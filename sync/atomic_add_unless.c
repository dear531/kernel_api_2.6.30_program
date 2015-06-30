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
	atomic_set(&v, 4);
#if 0
#define atomic_read(v)		((v)->counter + 0)
#endif
	printk(KERN_INFO "v :%d\n", atomic_read(&v));
#if 0
static __inline__ int atomic_add_unless(atomic_t *v, int a, int u)
#endif
	ret = atomic_add_unless(&v, 6, 10);
	printk(KERN_INFO "ret :%d, v :%d\n",
			ret, atomic_read(&v));

	ret = atomic_add_unless(&v, 6, 10);
	printk(KERN_INFO "ret :%d, v :%d\n",
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
