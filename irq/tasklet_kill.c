#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
void tasklet_func(unsigned long data)
{
	printk(KERN_INFO "%s\n", __func__);
	return;
}
static int __init tasklet_kill_init(void)
{
	struct tasklet_struct tasklet;
	printk(KERN_INFO "tasklet_kill_init\n");
	tasklet_init(&tasklet, tasklet_func, 0);
	printk(KERN_INFO "init tasklet.state :%ld\n", tasklet.state);
	tasklet_schedule(&tasklet);
	printk(KERN_INFO "schedule tasklet.state :%ld\n", tasklet.state);
	tasklet_disable(&tasklet);
	printk(KERN_INFO "disable tasklet.state :%ld\n", tasklet.state);
	tasklet_enable(&tasklet);
	printk(KERN_INFO "enable tasklet.state :%ld\n", tasklet.state);
	tasklet_kill(&tasklet);
	printk(KERN_INFO "kill tasklet.state :%ld\n", tasklet.state);
	return 0;
}

static void __exit tasklet_kill_exit(void)
{
	printk(KERN_INFO "tasklet_kill_exit\n");
}

module_init(tasklet_kill_init);
module_exit(tasklet_kill_exit);

MODULE_LICENSE("GPL");
