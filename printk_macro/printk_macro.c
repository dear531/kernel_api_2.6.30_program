#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/init.h>

static int __init printk_init(void)
{
#if 0
#define	KERN_EMERG	"<0>"	/* system is unusable			*/
#define	KERN_ALERT	"<1>"	/* action must be taken immediately	*/
#define	KERN_CRIT	"<2>"	/* critical conditions			*/
#define	KERN_ERR	"<3>"	/* error conditions			*/
#define	KERN_WARNING	"<4>"	/* warning conditions			*/
#define	KERN_NOTICE	"<5>"	/* normal but significant condition	*/
#define	KERN_INFO	"<6>"	/* informational			*/
#define	KERN_DEBUG	"<7>"	/* debug-level messages			*/
#endif
	printk(KERN_EMERG "<0>\n");
	printk(KERN_ALERT "<1>\n");
	printk(KERN_CRIT "<2>\n");
	printk(KERN_ERR "<3>\n");
	printk(KERN_WARNING "<4>\n");
	printk(KERN_NOTICE "<5>\n");
	printk(KERN_INFO "<6>\n");
	printk(KERN_DEBUG "<7>\n");

	return 0;
}

static void __exit printk_exit(void)
{
	printk(KERN_INFO "this is printk exit\n");
}

module_init(printk_init);
module_exit(printk_exit);

MODULE_LICENSE("GPL");

