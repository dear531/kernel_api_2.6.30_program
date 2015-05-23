#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

static int cpu = -1;

static int myfunc(void *arg)
{
	int data = -1;
	cpumask_var_t mask;
#if 0
static inline bool alloc_cpumask_var(cpumask_var_t *mask, gfp_t flags)
#endif
	alloc_cpumask_var(&mask, GFP_KERNEL);
#if 0
static inline void cpumask_set_cpu(unsigned int cpu, struct cpumask *dstp)
#endif
	cpumask_set_cpu(cpu, mask);
#if 0
static inline int set_cpus_allowed_ptr(struct task_struct *p,
				       const struct cpumask *new_mask)
#endif
	data = set_cpus_allowed_ptr(current->real_parent, mask);
#if 1
	printk(KERN_INFO "current->real_parent->pid :%d in child\n",
			current->real_parent->pid);
#endif
	printk(KERN_INFO "data :%d\n", data);
	return 0;
}

static int __init set_cpus_allowed_ptr_init(void)
{
	pid_t pid;
	struct pid *kpid;
	struct task_struct *task;
	struct thread_info *info;
	wait_queue_head_t head;
	wait_queue_t data;
	int remaintime;
	printk(KERN_INFO "set_cpus_allowed_ptr_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	kernel_thread(myfunc, NULL, CLONE_KERNEL);
#if 0
struct pid *find_get_pid(pid_t nr)
#endif
	kpid = find_get_pid(pid);
#if 0
enum pid_type
{
	PIDTYPE_PID,
	PIDTYPE_PGID,
	PIDTYPE_SID,
	PIDTYPE_MAX
};
struct task_struct *pid_task(struct pid *pid, enum pid_type type)
#endif
	task = pid_task(kpid, PIDTYPE_PID);
#if 0
static inline struct thread_info *current_thread_info(void)
#endif
	info = current_thread_info();
	cpu = (info->cpu == 0) ? 1 : 0;
	printk(KERN_INFO "cpu :%d\n", cpu);
#if 0
void init_waitqueue_head(wait_queue_head_t *q)
#endif
	init_waitqueue_head(&head);
#if 0
static inline void init_waitqueue_entry(wait_queue_t *q, struct task_struct *p)
#endif
	init_waitqueue_entry(&data, current);
#if 0
void add_wait_queue(wait_queue_head_t *q, wait_queue_t *wait)
#endif
	add_wait_queue(&head, &data);
#if 0
long __sched sleep_on_timeout(wait_queue_head_t *q, long timeout)
#endif
#if 1
	printk(KERN_INFO "parent pid :%d in parent\n",
			current->pid);
#endif
	printk(KERN_INFO "befor sleep_on_timeout cpu value :%d\n",
			info->cpu);
	remaintime = sleep_on_timeout(&head, 100);
	printk(KERN_INFO "remaintime :%d\n",
			remaintime);
	info = current_thread_info();
	printk(KERN_INFO "after sleep_on_timeout cpu value :%d\n",
			info->cpu);
	return 0;
}

static void __exit set_cpus_allowed_ptr_exit(void)
{
	printk(KERN_INFO "set_cpus_allowed_ptr_exit\n");
}

module_init(set_cpus_allowed_ptr_init);
module_exit(set_cpus_allowed_ptr_exit);

MODULE_LICENSE("GPL");
