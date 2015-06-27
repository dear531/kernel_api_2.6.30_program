#include <linux/init.h>
#include <linux/module.h>
#include <linux/timer.h>

struct timer_list timer;

void timer_func(unsigned long data)
{
	printk(KERN_INFO "%s\n", __func__);
	printk(KERN_INFO "data :%lx\n", data);
}
static int __init init_timer_key_init(void)
{
	printk(KERN_INFO "%s\n", __func__);
#if 0
void init_timer_key(struct timer_list *timer,
		    const char *name,
		    struct lock_class_key *key)
struct timer_list {
	struct list_head entry;
	unsigned long expires;

	void (*function)(unsigned long);
	unsigned long data;

	struct tvec_base *base;
#ifdef CONFIG_TIMER_STATS
	void *start_site;
	char start_comm[16];
	int start_pid;
#endif
#ifdef CONFIG_LOCKDEP
	struct lockdep_map lockdep_map;
#endif
};
#endif
	init_timer_key(&timer, NULL, NULL);
	timer.expires = jiffies + 1 * HZ;
	timer.data = &timer;
	timer.function = timer_func;
#if 0
void add_timer(struct timer_list *timer)
#endif
	add_timer(&timer);
	return 0;
}

static void __exit init_timer_key_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
	del_timer(&timer);
}

module_init(init_timer_key_init);
module_exit(init_timer_key_exit);

MODULE_LICENSE("GPL");
