#include <linux/init.h>
#include <linux/module.h>

static int __init read_seqbegin_init(void)
{
	seqlock_t sl;
	int ret, count = 0;
	printk(KERN_INFO "%s\n", __func__);
#if 0
typedef struct {
	unsigned sequence;
	spinlock_t lock;
} seqlock_t;
#define seqlock_init(x)
#endif
	seqlock_init(&sl);
	printk(KERN_INFO "seqlock_init sequence :%d, lock :%d\n",
			sl.sequence, sl.lock);
#if 0
static inline void write_seqlock(seqlock_t *sl)
#endif
	write_seqlock(&sl);
	printk(KERN_INFO "write_seqlock sequence :%d, lock :%d\n",
			sl.sequence, sl.lock);
#if 0
static inline void write_sequnlock(seqlock_t *sl)
#endif
	write_sequnlock(&sl);
	printk(KERN_INFO "write_sequnlock sequence :%d, lock :%d\n",
			sl.sequence, sl.lock);
#if 0
static __always_inline unsigned read_seqbegin(const seqlock_t *sl)
#endif
	ret = read_seqbegin(&sl);
	printk(KERN_INFO "read_seqbegin ret :%d\n", ret);
	printk(KERN_INFO "read_seqbegin sequence :%d, lock :%d\n",
			sl.sequence, sl.lock);
#if 0
static inline void write_seqlock(seqlock_t *sl)
#endif
	write_seqlock(&sl);
	printk(KERN_INFO "try write_seqlock sequence :%d, lock :%d\n",
			sl.sequence, sl.lock);
#if 0
static inline void write_sequnlock(seqlock_t *sl)
#endif
	write_sequnlock(&sl);
	printk(KERN_INFO "try write_sequnlock sequence :%d, lock :%d\n",
			sl.sequence, sl.lock);
	do {
		ret = read_seqbegin(&sl);
		printk(KERN_INFO "try read_seqbegin count :%d\n", count++);
	} while (read_seqretry(&sl, ret));
	printk(KERN_INFO "try read_seqbegin sequence :%d, lock :%d\n",
			sl.sequence, sl.lock);
	return 0;
}

static void __exit read_seqbegin_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(read_seqbegin_init);
module_exit(read_seqbegin_exit);

MODULE_LICENSE("GPL");
