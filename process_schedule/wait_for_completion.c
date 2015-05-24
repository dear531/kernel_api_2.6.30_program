#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

int myfunc(void *arg)
{
	wait_queue_head_t head;
	wait_queue_t data;
	printk(KERN_INFO "into %s \n", __func__);
	init_waitqueue_head(&head);
	init_waitqueue_entry(&data, current);
	add_wait_queue(&head, &data);
#if 0
long __sched sleep_on_timeout(wait_queue_head_t *q, long timeout)
#endif
	printk(KERN_INFO "become sleep_on_timeout in child pid :%d\n",
			current->pid);
	sleep_on_timeout(&head, 100);
	printk(KERN_INFO "wake_up in child\n");
	printk(KERN_INFO "out %s\n", __func__);
	return 0;
}

static int wait_for_completion_init(void)
{
	pid_t pid;
	struct pid *kpid;
	struct task_struct *task;
	struct completion comple;
	wait_queue_t data;
	printk(KERN_INFO "wait_for_completion\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
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
static inline void init_completion(struct completion *x)
#endif
	init_completion(&comple);
#if 0
static inline void init_waitqueue_entry(wait_queue_t *q, struct task_struct *p)
#endif
	init_waitqueue_entry(&data, task);
#if 0
void add_wait_queue(wait_queue_head_t *q, wait_queue_t *wait)
#endif
	__add_wait_queue_tail(&comple.wait, &data);
#if 0
void __sched wait_for_completion(struct completion *x)
#endif
	complete(&comple);
	printk(KERN_INFO "befor wait_for_completion comple.done :%d\n",
			comple.done);
	wait_for_completion(&comple);
	printk(KERN_INFO "after wait_for_completion comple.done :%d\n",
			comple.done);
	return 0;
}

static void wait_for_completion_exit(void)
{
	printk(KERN_INFO "wait_for_completion_exit\n");
}

module_init(wait_for_completion_init);
module_exit(wait_for_completion_exit);

MODULE_LICENSE("GPL");
