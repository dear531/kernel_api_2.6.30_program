#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	printk(KERN_INFO "pid :%d\n",
			current->pid);
	return 0;
}

static int __init prepare_to_wait_init(void)
{
	pid_t pid1, pid2;
	struct pid *kpid1, *kpid2;
	struct task_struct *task1, *task2;
	wait_queue_head_t head;
	wait_queue_t data1, data2, *curr, *next;
	int wait_queue_num;
	printk(KERN_INFO "prepare_to_wait_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid1 = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	pid2 = kernel_thread(myfunc, NULL, CLONE_KERNEL);
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
#if 0
void
prepare_to_wait(wait_queue_head_t *q, wait_queue_t *wait, int state)
void
prepare_to_wait(wait_queue_head_t *q, wait_queue_t *wait, int state)
{
	unsigned long flags;

	wait->flags &= ~WQ_FLAG_EXCLUSIVE;
	spin_lock_irqsave(&q->lock, flags);
	if (list_empty(&wait->task_list))
		__add_wait_queue(q, wait);
	set_current_state(state);
	spin_unlock_irqrestore(&q->lock, flags);
}
void add_wait_queue(wait_queue_head_t *q, wait_queue_t *wait)
{
	unsigned long flags;

	wait->flags &= ~WQ_FLAG_EXCLUSIVE;
	spin_lock_irqsave(&q->lock, flags);
	__add_wait_queue(q, wait);
	spin_unlock_irqrestore(&q->lock, flags);
}
#endif
	data1.task_list.next = &data1.task_list;
	prepare_to_wait(&head, &data1, 1);
	printk(KERN_INFO "after prepare_to_wait to value 1 current->state %ld in %d\n",
			current->state, current->pid);
#if 0
list_for_each_entry_safe(pos, n, head, member)
#endif
	wait_queue_num = 0;
	list_for_each_entry_safe(curr, next, &head.task_list, task_list) {
		wait_queue_num++;
		printk(KERN_INFO "curr->flags :%d\n", curr->flags);
		printk(KERN_INFO "curr->private->state :%ld\n",
				((struct task_struct *)curr->private)->state);
		printk(KERN_INFO "curr->private->pid:%d\n",
				((struct task_struct *)curr->private)->pid);
	}
	printk(KERN_INFO "wait_queue_num :%d\n", wait_queue_num);
#if 1
	init_waitqueue_entry(&data2, task2);
	data2.task_list.next = &data2.task_list;
	prepare_to_wait(&head, &data2, 0);
	printk(KERN_INFO "after prepare_to_wait to value 2 current->state %ld in %d\n",
			current->state, current->pid);

	wait_queue_num = 0;
	list_for_each_entry_safe(curr, next, &head.task_list, task_list) {
		wait_queue_num++;
		printk(KERN_INFO "curr->flags :%d\n", curr->flags);
		printk(KERN_INFO "curr->private->state :%ld\n",
				((struct task_struct *)curr->private)->state);
		printk(KERN_INFO "curr->private->pid:%d\n",
				((struct task_struct *)curr->private)->pid);
	}
	printk(KERN_INFO "wait_queue_num :%d\n", wait_queue_num);
#endif

	return 0;
}

static void __exit prepare_to_wait_exit(void)
{
	printk(KERN_INFO "prepare_to_wait_exit\n");
}

module_init(prepare_to_wait_init);
module_exit(prepare_to_wait_exit);

MODULE_LICENSE("GPL");
