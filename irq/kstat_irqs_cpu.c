#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/irq.h>
#include <linux/interrupt.h>
#include <linux/kernel_stat.h>

unsigned int irq = 0;
int cpu = 0;

static int __init kstat_irqs_cpu_init(void)
{
	unsigned int num;
	printk(KERN_INFO "kstat_irqs_cpus_init\n");
#if 0
static inline unsigned int kstat_irqs_cpu(unsigned int irq, int cpu)
#endif
	for (irq = 0; NR_IRQS > irq; irq++) {
		printk(KERN_INFO "irq :%d ", irq);
		for (cpu = 0; NR_CPUS > cpu; cpu++) {
			num = kstat_irqs_cpu(irq, cpu);
			printk(KERN_INFO "cpu:%d n:%d\n", cpu, num);
		}
	}
	printk(KERN_INFO "NR_CPUS :%d\n", NR_CPUS);
	printk(KERN_INFO "NR_IRQS :%d\n", NR_IRQS);
	return 0;
}

static void __exit kstat_irqs_cpu_exit(void)
{
	printk(KERN_INFO "kstat_irqs_cpus_exit\n");
}

module_init(kstat_irqs_cpu_init);
module_exit(kstat_irqs_cpu_exit);

MODULE_LICENSE("GPL");
