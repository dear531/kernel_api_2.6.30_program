#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>
struct completion comple;

static int myfunc(void *arg)
{
	wait_queue_head_t head;
	long remaintime;
	wait_queue_t data;
	int ret;
	printk(KERN_INFO "into %s \n", __func__);
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
	remaintime = sleep_on_timeout(&head, 10);
	printk(KERN_INFO "remaintime :%ld\n", remaintime);
#if 0
void complete(struct completion *x)
#endif
	complete(&comple);
	printk(KERN_INFO "comlete comple.done %d\n", comple.done);
#if 0
bool try_wait_for_completion(struct completion *x)
#endif
	ret = try_wait_for_completion(&comple);
	printk(KERN_INFO "try_wait_for_completion result :%d\n", ret);
	printk(KERN_INFO "try_wait_for_completion comple.done %d\n", comple.done);
	printk(KERN_INFO "child pid :%d in child\n", current->pid);
	printk(KERN_INFO "parent state :%ld in child \n", current->real_parent->state);
	complete(&comple);
	printk(KERN_INFO "try complete comple.done %d\n", comple.done);
	printk(KERN_INFO "out %s\n", __func__);

	return 0;
}

static int __init try_wait_for_completion_init(void)
{
	pid_t pid;
	struct pid *kpid;
	struct task_struct *task;
	wait_queue_t data;
	printk(KERN_INFO "try_wait_for_completion_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid = kernel_thread(myfunc, NULL, CLONE_KERNEL);
#if 0
struct pid *find_get_pid(pid_t nr)
#endif
	kpid = find_get_pid(pid);
#if 0
struct task_struct *pid_task(struct pid *pid, enum pid_type type)
enum pid_type
{
	PIDTYPE_PID,
	PIDTYPE_PGID,
	PIDTYPE_SID,
	PIDTYPE_MAX
};
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
static inline void __add_wait_queue_tail(wait_queue_head_t *head,
						wait_queue_t *new)
#endif
	__add_wait_queue_tail(&comple.wait, &data);
#if 0
void __sched wait_for_completion(struct completion *x)
#endif
	printk(KERN_INFO "comple.done :%d in parent\n", comple.done);
	wait_for_completion(&comple);
	printk(KERN_INFO "comple.done :%d in parent\n", comple.done);
	return 0;
}

static void __exit try_wait_for_completion_exit(void)
{
	printk(KERN_INFO "try_wait_for_completion_exit\n");
}

module_init(try_wait_for_completion_init);
module_exit(try_wait_for_completion_exit);

MODULE_LICENSE("GPL");
