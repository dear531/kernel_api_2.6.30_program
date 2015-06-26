#include <linux/init.h>
#include <linux/module.h>
#include <linux/timer.h>

struct timer_list my_timer;

#if 0
void (*function)(unsigned long);
#endif
void my_timer_fucn(unsigned long data)
{
	printk(KERN_INFO "%s\n", __func__);
	printk(KERN_INFO "data :%ld\n", data);
}

static int __init timer_init(void)
{
	printk(KERN_INFO "%s\n", __func__);
	init_timer(&my_timer);
	my_timer.expires = jiffies + 1 * HZ;
	my_timer.data = &my_timer;
	my_timer.function = my_timer_fucn;
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
	add_timer(&my_timer);
	return 0;
}

static void __exit timer_exit(void)
{
	int ret;
	printk(KERN_INFO "%s\n", __func__);
#if 0
int del_timer(struct timer_list *timer)
#endif
	ret = del_timer(&my_timer);
	printk(KERN_INFO "del_timer result :%d\n", ret);
}

module_init(timer_init);
module_exit(timer_exit);

MODULE_LICENSE("GPL");
