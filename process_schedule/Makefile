ifneq ($(KERNELRELEASE),)
	obj-m	:=wake_up.o wake_up_sync.o wake_up_sync_key.o \
		  abort_exclusive_wait.o add_preempt_count.o \
		  add_wait_queue.o add_wait_queue_exclusive.o \
		  autoremove_wake_function.o complete.o \
		  complete_all.o completion_done.o \
		  current_thread_info.o
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
