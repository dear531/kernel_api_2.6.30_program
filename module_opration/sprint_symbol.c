#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/kallsyms.h>

extern int sym_a(void);

static int __init sprint_symbol_init(void)
{
	char buff[KSYM_SYMBOL_LEN] = {0};
	unsigned long address;
	int len;
	printk(KERN_INFO "sprint_symbol_init\n");
	address = (unsigned long)__builtin_return_address(0);
	len = sprint_symbol(buff, address);
	printk(KERN_INFO "first buff:%s\nlen :%d\n", buff, len);

	address = (unsigned long)__builtin_return_address(0);
	memset(buff, 0x00, sizeof(buff) / sizeof(*buff));
	len = sprint_symbol(buff, address);
	printk(KERN_INFO "first buff:%s\nlen :%d\n", buff, len);

	address = (unsigned long)sprint_symbol_init;
	memset(buff, 0x00, sizeof(buff) / sizeof(*buff));
	len = sprint_symbol(buff, address);
	printk(KERN_INFO "first buff:%s\nlen :%d\n", buff, len);
	
	address = (unsigned long)sym_a;
	memset(buff, 0x00, sizeof(buff) / sizeof(*buff));
	len = sprint_symbol(buff, address);
	printk(KERN_INFO "first buff:%s\nlen :%d\n", buff, len);

	address = (unsigned long)sym_a + 5;
	memset(buff, 0x00, sizeof(buff) / sizeof(*buff));
	len = sprint_symbol(buff, address);
	printk(KERN_INFO "first buff:%s\nlen :%d\n", buff, len);

	return 0;
}

static void __exit sprint_symbol_exit(void)
{
	printk(KERN_INFO "sprint_symbol_exit\n");
}

module_init(sprint_symbol_init);
module_exit(sprint_symbol_exit);

MODULE_LICENSE("GPL");
