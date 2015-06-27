#include <linux/init.h>
#include <linux/module.h>
#include <linux/timer.h>

struct timer_list timer;

void timer_func(unsigned long data)
{
	printk(KERN_INFO "%s\n", __func__);
	printk(KERN_INFO "data :%d\n", data);
}

static int __init mod_timer_init(void)
{
	printk(KERN_INFO "%s\n", __func__);
	init_timer(&timer);
	timer.expires = jiffies + 1 * HZ;
	timer.data = &timer;
	timer.function = timer_func;
#if 0
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
void add_timer(struct timer_list *timer)
#endif
	add_timer(&timer);
	printk(KERN_INFO "befor mod_timer timer.expires :%lx\n", timer.expires);
	mod_timer(&timer, timer.expires + 1 * HZ);
	printk(KERN_INFO "after mod_timer timer.expires :%lx\n", timer.expires);
#if 0
int mod_timer(struct timer_list *timer, unsigned long expires)
#endif
	return 0;
}

static void __exit mod_timer_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(mod_timer_init);
module_exit(mod_timer_exit);

MODULE_LICENSE("GPL");
