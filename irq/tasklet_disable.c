#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
struct tasklet_struct tasklet;
void tasklet_func(unsigned long data)
{
	printk(KERN_INFO "%s data %ld pid %d\n",
			__func__, data, current->pid);
	return;
}

static int __init tasklet_disable_init(void)
{
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
static inline void tasklet_disable(struct tasklet_struct *t)
#endif
	tasklet_disable(&tasklet);
	printk(KERN_INFO "tasklet.count :%d\n", tasklet.count);

	tasklet_enable(&tasklet);
	printk(KERN_INFO "tasklet.count :%d\n", tasklet.count);
#if 0	
void tasklet_kill(struct tasklet_struct *t)
#endif
	tasklet_kill(&tasklet);
	printk(KERN_INFO "main process pid :%d\n",
			current->pid);

	return 0;
}

static void __exit tasklet_disable_exit(void)
{
	printk(KERN_INFO "%s\n", __func__);
}

module_init(tasklet_disable_init);
module_exit(tasklet_disable_exit);

MODULE_LICENSE("GPL");
