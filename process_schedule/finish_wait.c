#include <linux/init.h>
#include <linux/module.h>
#include <linux/kernel.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	printk(KERN_INFO "current->pid :%d, current->state :%ld\n",
			current->pid, current->state);
	return 0;
}

static int __init finish_wait_init(void)
{
	wait_queue_head_t head;
	wait_queue_t data1, data2, *curr, *next;
	pid_t pid1, pid2;
	struct pid *kpid1, *kpid2;
	struct task_struct *task1, *task2;
	int wait_queue_num;
	printk(KERN_INFO "finish_wait_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid1 = kernel_thread(myfunc, &head, CLONE_KERNEL);
	pid2 = kernel_thread(myfunc, &head, CLONE_KERNEL);
#if 0
struct pid *find_get_pid(pid_t nr)
#endif
	kpid1 = find_get_pid(pid1);
	kpid2 = find_get_pid(pid2);
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
	task1 = pid_task(kpid1, PIDTYPE_PID);
	task2 = pid_task(kpid2, PIDTYPE_PID);
#if 0
void init_waitqueue_head(wait_queue_head_t *q)
#endif
	init_waitqueue_head(&head);
#if 0
static inline void init_waitqueue_entry(wait_queue_t *q, struct task_struct *p)
#endif
	init_waitqueue_entry(&data1, task1);
	task1->state = 1;
	init_waitqueue_entry(&data2, task2);
	task1->state = 2;
#if 0
struct __wait_queue {
	unsigned int flags;
#define WQ_FLAG_EXCLUSIVE	0x01
	void *private;
	wait_queue_func_t func;
	struct list_head task_list;
};
static inline void INIT_LIST_HEAD(struct list_head *list)
#endif
	INIT_LIST_HEAD(&data1.task_list);
	INIT_LIST_HEAD(&data2.task_list);
#if 0
void add_wait_queue(wait_queue_head_t *q, wait_queue_t *wait)
#endif
	add_wait_queue(&head, &data1);
	add_wait_queue(&head, &data2);
#if 0
list_for_each_entry_safe(pos, n, head, member)
#endif
	wait_queue_num = 0;
	list_for_each_entry_safe (curr, next, &head.task_list, task_list) {
		wait_queue_num++;
		printk(KERN_INFO "curr->private->pid :%d, curr->flags %d\n",
				((struct task_struct *)curr->private)->pid,
				curr->flags);
		printk(KERN_INFO "curr->private->state :%ld\n",
				((struct task_struct *)curr->private)->state);
	}
	printk(KERN_INFO "wait_queue_num :%d\n", wait_queue_num);
#if 0
void finish_wait(wait_queue_head_t *q, wait_queue_t *wait)
#endif
	finish_wait(&head, &data1);

	wait_queue_num = 0;
	list_for_each_entry_safe (curr, next, &head.task_list, task_list) {
		wait_queue_num++;
		printk(KERN_INFO "curr->private->pid :%d, curr->flags %d\n",
				((struct task_struct *)curr->private)->pid,
				curr->flags);
		printk(KERN_INFO "curr->private->state :%ld\n",
				((struct task_struct *)curr->private)->state);
	}
	printk(KERN_INFO "wait_queue_num :%d\n", wait_queue_num);

	return 0;
}

static void __exit finish_wait_exit(void)
{
	printk(KERN_INFO "finish_wait_exit\n");
}

module_init(finish_wait_init);
module_exit(finish_wait_exit);

MODULE_LICENSE("GPL");
