#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int __init add_preempt_count_init(void)
{
	int val = 1;
	struct thread_info *info;
	printk(KERN_INFO "add_preempt_count_init\n");
#if 0
struct thread_info {
	struct pcb_struct	pcb;		/* palcode state */

	struct task_struct	*task;		/* main task structure */
	unsigned int		flags;		/* low level flags */
	unsigned int		ieee_state;	/* see fpu.h */

	struct exec_domain	*exec_domain;	/* execution domain */
	mm_segment_t		addr_limit;	/* thread address space */
	unsigned		cpu;		/* current CPU */
	int			preempt_count; /* 0 => preemptable, <0 => BUG */

	int bpt_nsaved;
	unsigned long bpt_addr[2];		/* breakpoint handling  */
	unsigned int bpt_insn[2];

	struct restart_block	restart_block;
};
static inline struct thread_info *current_thread_info(void)
#endif
	printk(KERN_INFO "curren->pid :%d\n",
			current->pid);
	info = current_thread_info();
	printk(KERN_INFO "befor add_preempt_count info->preempt_count :%d\n",
			info->preempt_count);
	add_preempt_count(val);
	printk(KERN_INFO "after add_preempt_count info->preempt_count :%d\n",
			info->preempt_count);
	return 0;
}

static void __exit add_preempt_count_exit(void)
{
	printk(KERN_INFO "add_preempt_count_exit\n");
}

module_init(add_preempt_count_init);
module_exit(add_preempt_count_exit);

MODULE_LICENSE("GPL");
