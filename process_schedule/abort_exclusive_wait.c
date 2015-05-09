#include <linux/init.h>
#include <linux/kernel.h>
#include <linux/module.h>
#include <linux/pid.h>
#include <linux/sched.h>

static int myfunc(void *arg)
{
	return 0;
}

static int __init abort_exclusive_wait_init(void)
{
	pid_t pid1, pid2, pid3;
	struct pid *kpid1, *kpid2, *kpid3;
	struct task_struct *task1, *task2, *task3;
	int waitqueue_num;
	wait_queue_head_t head;
	wait_queue_t data1, data2, data3, *curr, *next;
	printk(KERN_INFO "abort_exclusive_wait_init\n");

	pid1 = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	kpid1 = find_get_pid(pid1);
	task1 = pid_task(kpid1, PIDTYPE_PID);

	pid2 = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	kpid2 = find_get_pid(pid2);
	task2 = pid_task(kpid2, PIDTYPE_PID);

	pid3 = kernel_thread(myfunc, NULL, CLONE_KERNEL);
	kpid3 = find_get_pid(pid3);
	task3 = pid_task(kpid3, PIDTYPE_PID);
	printk(KERN_INFO "1 :%d, 2: %d, 3: %d\n",
			pid1, pid2, pid3);

	/* create wait queue head */
	init_waitqueue_head(&head);

	init_waitqueue_entry(&data1, task1);
	INIT_LIST_HEAD(&data1.task_list);
	//data1.task_list.next = &data1.task_list;
	prepare_to_wait(&head, &data1, 130);
	printk(KERN_INFO "after 130 current->state :%ld\n", current->state);

	init_waitqueue_entry(&data2, task2);
	INIT_LIST_HEAD(&data2.task_list);
	//data2.task_list.next = &data2.task_list;
	prepare_to_wait_exclusive(&head, &data2, 1);
	printk(KERN_INFO "after 1 current->state :%ld\n", current->state);

	init_waitqueue_entry(&data3, task3);
	INIT_LIST_HEAD(&data3.task_list);
	//data3.task_list.next = &data3.task_list;
	prepare_to_wait_exclusive(&head, &data3, 2);
	printk(KERN_INFO "after 2 current->state :%ld\n", current->state);
	
	waitqueue_num = 0;
	list_for_each_entry_safe(curr, next,
			&head.task_list, task_list) {
		waitqueue_num++;
		printk(KERN_INFO "curr->pid :%d\n",
				((struct task_struct *)curr->private)->pid);
		printk(KERN_INFO "curr->state :%ld\n",
				((struct task_struct *)curr->private)->state);
	}
	printk(KERN_INFO "waitqueue_num :%d\n", waitqueue_num);
	printk(KERN_INFO "current->state :%ld\n", current->state);
#if 0
void abort_exclusive_wait(wait_queue_head_t *q, wait_queue_t *wait,
			unsigned int mode, void *key)
#endif
	((struct task_struct *)data2.private)->state = 130;
#if 0
void finish_wait(wait_queue_head_t *q, wait_queue_t *wait)
#endif
	finish_wait(&head, &data1);

	printk(KERN_INFO "after changed state\n");

	waitqueue_num = 0;
	list_for_each_entry_safe(curr, next,
			&head.task_list, task_list) {
		waitqueue_num++;
		printk(KERN_INFO "curr->pid :%d\n",
				((struct task_struct *)curr->private)->pid);
		printk(KERN_INFO "curr->state :%ld\n",
				((struct task_struct *)curr->private)->state);
	}
	printk(KERN_INFO "waitqueue_num :%d\n", waitqueue_num);
	printk(KERN_INFO "current->state :%ld\n", current->state);

	abort_exclusive_wait(&head, &data2, TASK_NORMAL, NULL);

	printk(KERN_INFO "after abort_exclusive_wait data2\n");

	waitqueue_num = 0;
	list_for_each_entry_safe(curr, next,
			&head.task_list, task_list) {
		waitqueue_num++;
		printk(KERN_INFO "curr->pid :%d\n",
				((struct task_struct *)curr->private)->pid);
		printk(KERN_INFO "curr->state :%ld\n",
				((struct task_struct *)curr->private)->state);
	}
	printk(KERN_INFO "waitqueue_num :%d\n", waitqueue_num);
	printk(KERN_INFO "current->state :%ld\n", current->state);

	return 0;
}

static void __exit abort_exclusive_wait_exit(void)
{
	printk(KERN_INFO "abort_exclusive_wait_exit\n");
}

module_init(abort_exclusive_wait_init);
module_exit(abort_exclusive_wait_exit);

MODULE_LICENSE("GPL");
