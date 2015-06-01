#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
struct tasklet_struct tasklet;
void tasklet_func(unsigned long data)
{
	int ret;
#if 0
static inline int tasklet_trylock(struct tasklet_struct *t)
#endif
	ret = tasklet_trylock(&tasklet);
	printk(KERN_INFO "%s tasklet_trylock ret %d\n", __func__, ret);
	return;
}
static int __init tasklet_trylock_unlock_init(void)
{
	int ret;
	printk(KERN_INFO "%s\n", __func__);
#if 0
void tasklet_init(struct tasklet_struct *t,
		  void (*func)(unsigned long), unsigned long data)
#endif
	tasklet_init(&tasklet, tasklet_func, 1);
#if 0
static inline void tasklet_schedule(struct tasklet_struct *t)
#endif
	tasklet_schedule(&tasklet);
#if 0
static inline int tasklet_trylock(struct tasklet_struct *t)
#endif
	printk(KERN_INFO "schedule tasklet.state :%ld\n", tasklet.state);
	ret = tasklet_trylock(&tasklet);
	if (0 == ret)
		printk(KERN_INFO "tasklet_trylock failed\n");
	else
		printk(KERN_INFO "tasklet_trylock success\n");
	printk(KERN_INFO "trylock tasklet.state :%ld\n", tasklet.state);
#if 0
static inline void tasklet_unlock(struct tasklet_struct *t)
#endif
	tasklet_unlock(&tasklet);
	printk(KERN_INFO "unlock tasklet.state :%ld\n", tasklet.state);
	tasklet_kill(&tasklet);
	return 0;
}

static void __exit tasklet_trylock_unlock_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(tasklet_trylock_unlock_init);
module_exit(tasklet_trylock_unlock_exit);

MODULE_LICENSE("GPL");
