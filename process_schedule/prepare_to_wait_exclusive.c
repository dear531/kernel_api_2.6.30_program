#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	return 0;
}

static int __init prepare_to_wait_exclusive_init(void)
{
	pid_t pid1, pid2, pid3;
	struct pid *kpid1, *kpid2, *kpid3;
	struct task_struct *task1, *task2, *task3;
	wait_queue_head_t head;
	wait_queue_t data1, data2, data3, *curr, *next;
	int wait_queue_num;
	printk(KERN_INFO "prepare_to_wait_exclusive_init\n");
#if 0
pid_t kernel_thread(int (*fn)(void *), void *arg, unsigned long flags)
#endif
	pid1 = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	pid2 = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	pid3 = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	printk(KERN_INFO "pid1 :%d, pid2 :%d, pid3 :%d\n",
			pid1, pid2, pid3);
#if 0
struct pid *find_get_pid(pid_t nr)
#endif
	kpid1 = find_get_pid(pid1);
	kpid2 = find_get_pid(pid2);
	kpid3 = find_get_pid(pid3);
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
	task3 = pid_task(kpid3, PIDTYPE_PID);
#if 0
void init_waitqueue_head(wait_queue_head_t *q)
#endif
	init_waitqueue_head(&head);
#if 0
static inline void init_waitqueue_entry(wait_queue_t *q, struct task_struct *p)
#endif
	init_waitqueue_entry(&data1, task1);
#if 0
prepare_to_wait_exclusive(wait_queue_head_t *q, wait_queue_t *wait, int state)
#endif
	data1.task_list.next = &data1.task_list;
	prepare_to_wait_exclusive(&head, &data1, 1);
#if 0
list_for_each_entry_safe(pos, n, head, member)
#endif
	wait_queue_num = 0;
	list_for_each_entry_safe (curr, next, &head.task_list, task_list) {
		wait_queue_num++;
		printk(KERN_INFO "curr->private->pid :%d, curr->flags :%d\n",
				((struct task_struct *)curr->private)->pid,
				curr->flags);
	}
	printk(KERN_INFO "wait_queue_num :%d\n", wait_queue_num);
	printk(KERN_INFO "current->state :%ld\n",
			current->state);

	init_waitqueue_entry(&data2, task2);
	data2.task_list.next = &data2.task_list;
	prepare_to_wait_exclusive(&head, &data2, 130);

	printk(KERN_INFO "current->state :%ld\n",
			current->state);

	init_waitqueue_entry(&data3, task3);
	data3.task_list.next = &data3.task_list;
	prepare_to_wait(&head, &data3, 1);

	wait_queue_num = 0;
	list_for_each_entry_safe (curr, next, &head.task_list, task_list) {
		wait_queue_num++;
		printk(KERN_INFO "curr->private->pid :%d, curr->flags :%d\n",
				((struct task_struct *)curr->private)->pid,
				curr->flags);
	}
	printk(KERN_INFO "wait_queue_num :%d\n", wait_queue_num);
	printk(KERN_INFO "current->state :%ld\n",
			current->state);
	return 0;
}

static void __exit prepare_to_wait_exclusive_exit(void)
{
	printk(KERN_INFO "prepare_to_wait_exclusive_exit\n");
}

module_init(prepare_to_wait_exclusive_init);
module_exit(prepare_to_wait_exclusive_exit);

MODULE_LICENSE("GPL");
