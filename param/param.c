#include <linux/init.h>
#include <linux/module.h>
#include <linux/moduleparam.h>
#include <linux/sched.h>

static int num = 0;
static char *p[10] = {NULL};

module_param_array(p, charp, &num, S_IRUGO);

static int __init param_init(void)
{
	int i;
	printk(KERN_ALERT "current->pid:%d,current->comm:%s",
			current->pid, current->comm);
	for (i = 0; num > i; i++)
		printk(KERN_ALERT "p[%d]:%s\n",
				i, p[i]);
	printk(KERN_ALERT "num :%d\n", num);
	return 0;
}

static void __exit param_exit(void)
{
	printk(KERN_ALERT "param_exit\n");
}

module_init(param_init);
module_exit(param_exit);

MODULE_LICENSE("gpl");
MODULE_AUTHOR("zhangly");
MODULE_VERSION("2.6.30");
MODULE_ALIAS();
MODULE_DESCRIPTION();
