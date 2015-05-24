ifneq ($(KERNELRELEASE),)
	obj-m	:=wake_up.o wake_up_sync.o wake_up_sync_key.o \
		  abort_exclusive_wait.o add_preempt_count.o \
		  add_wait_queue.o add_wait_queue_exclusive.o \
		  autoremove_wake_function.o complete.o \
		  complete_all.o completion_done.o \
		  current_thread_info.o default_wake_function.o \
		  do_exit.o finish_wait.o init_waitqueue_entry.o \
		  init_waitqueue_head.o interruptible_sleep_on.o \
		  interruptible_sleep_on_timeout.o preempt_notifier_register.o \
		  preempt_notifier_unregister.o prepare_to_wait.o \
		  prepare_to_wait_exclusive.o remote_wait_queue.o \
		  sched_setscheduler.o set_cpus_allowed_ptr.o \
		  set_user_nice.o sleep_on.o sleep_on_timeout.o \
		  sub_preempt_count.o task_nice.o try_wait_for_completion.o \
		  wait_for_completion.o wait_for_completion_interruptible.o \
		  wait_for_completion_interruptible_timeout.o \
		  wake_up_process.o
else
	PWD	:=$(shell pwd)
	KVER	:=$(shell uname -r)
	KDIR	:=/lib/modules/$(KVER)/build/
default:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	-rm -rf *.ko *.o .*.cmd *.mod.c modules.order \
		Module.symvers .tmp_versions
endif
