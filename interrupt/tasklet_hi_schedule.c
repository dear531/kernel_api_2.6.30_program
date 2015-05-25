#include <linux/init.h>
#include <linux/module.h>
#include <linux/interrupt.h>
#include <linux/irq.h>

struct tasklet_struct tasklet1, tasklet2;
unsigned long data = 0;

void task_func1(unsigned long data)
{
	printk(KERN_INFO "this is %s data :%ld\n", __func__, data);
	printk(KERN_INFO "tasklet1.state :%ld\n", tasklet1.state);
}

void task_func2(unsigned long data)
{
	printk(KERN_INFO "this is %s data :%ld\n", __func__, data);
	printk(KERN_INFO "tasklet2.state :%ld\n", tasklet2.state);
}

static int __init tasklet_hi_schedule_init(void)
{
	printk(KERN_INFO "tasklet_hi_schedule_init\n");
#if 0
struct tasklet_struct
{
	struct tasklet_struct *next;
	unsigned long state;
	atomic_t count;
	void (*func)(unsigned long);
	unsigned long data;
};
void tasklet_init(struct tasklet_struct *t,
		  void (*func)(unsigned long), unsigned long data)
#endif
	tasklet_init(&tasklet1, task_func1, data);
	tasklet_init(&tasklet2, task_func2, data);
	printk(KERN_INFO "takslet1->state :%ld\n", tasklet1.state);
	printk(KERN_INFO "takslet2->state :%ld\n", tasklet2.state);
#if 0
static inline void tasklet_schedule(struct tasklet_struct *t)
#endif
	tasklet_schedule(&tasklet1);
#if 1
	tasklet_schedule(&tasklet2);
#else
#if 0
void __tasklet_hi_schedule(struct tasklet_struct *t)
#endif
	if (!test_and_set_bit(TASKLET_STATE_SCHED, &tasklet2.state))
		__tasklet_hi_schedule(&tasklet2);
#endif
#if 0
void tasklet_kill(struct tasklet_struct *t)
#endif
	tasklet_kill(&tasklet1);
	tasklet_kill(&tasklet2);
	printk(KERN_INFO "out %s\n", __func__);
	return 0;
}

static void __exit tasklet_hi_schedule_exit(void)
{
	printk(KERN_INFO "tasklet_hi_schedule_exit\n");
}

module_init(tasklet_hi_schedule_init);
module_exit(tasklet_hi_schedule_exit);

MODULE_LICENSE("GPL");
