#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/irq.h>

struct tasklet_struct tasklet;
unsigned long data = 0;

void tasklet_func(unsigned long data)
{
	printk(KERN_INFO "into %s\n", __func__);
	printk(KERN_INFO "data :%ld current->pid :%d\n",
			data, current->pid);
	printk(KERN_INFO "tasklet state :%ld\n",
			tasklet.state);
	printk(KERN_INFO "out %s\n", __func__);
	return;
}

static int __init __tasklet_schedule_init(void)
{
	printk(KERN_INFO "__tasklet_schedule_init\n");
#if 0
void tasklet_init(struct tasklet_struct *t,
		  void (*func)(unsigned long), unsigned long data)
#endif
	tasklet_init(&tasklet, tasklet_func, data);
#if 0
void __tasklet_schedule(struct tasklet_struct *t)
#endif
	printk(KERN_INFO "set tasklet state :%ld\n",
			tasklet.state);
	if (!test_and_set_bit(TASKLET_STATE_SCHED, &tasklet.state))
		__tasklet_schedule(&tasklet);
	printk(KERN_INFO "set end tasklet state :%ld\n",
			tasklet.state);
	return 0;
}

static void __exit __tasklet_schedule_exit(void)
{
	printk(KERN_INFO "__tasklet_schedule_exit\n");
}

module_init(__tasklet_schedule_init);
module_exit(__tasklet_schedule_exit);

MODULE_LICENSE("GPL");
