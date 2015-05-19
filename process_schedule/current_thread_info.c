#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/wait.h>
#include <linux/sched.h>

static int __init current_thread_info_init(void)
{
	struct thread_info *thread_info;
	printk(KERN_INFO "current_thread_info_init\n");
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
	thread_info = current_thread_info();
	printk(KERN_INFO "thread_info->task->pid :%d\n",
			thread_info->task->pid);
	printk(KERN_INFO "thread_info->task->tpid :%d\n",
			thread_info->task->tgid);
	printk(KERN_INFO "current->pid :%d, current->tgid :%d\n",
			current->pid, current->tgid);
	printk(KERN_INFO "thread_info->preempt_count :%d\n",
			thread_info->preempt_count);
	return 0;
}

static void __exit current_thread_info_exit(void)
{
	printk(KERN_INFO "current_thread_info_exit\n");
}

module_init(current_thread_info_init);
module_exit(current_thread_info_exit);

MODULE_LICENSE("GPL");
