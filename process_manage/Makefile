ifneq ($(KERNELRELEASE),)
	obj-m	:=task_pid_nr_ns.o find_get_pid.o find_pid_ns.o \
		  find_pid_ns.o find_task_by_pid_ns.o find_task_by_pid_type_ns.o \
		  find_task_by_vpid.o find_vpid.o get_pid.o get_task_mm.o \
		  is_container_init.o kernel_thread.o mmput.o ns_of_pid.o \
		  pid_nr.o pid_task.o pid_vnr.o put_pid.o task_active_pid_ns.o \
		  task_tgid_nr_ns.o
else
	PWD	:=$(shell pwd)
	KVER	:=$(shell uname -r)
	KDIR	:=/lib/modules/$(KVER)/build/
default:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	-rm -rf *.o *.ko .*.cmd *.mod.c modules.order \
		Module.symvers .tmp_versions
endif
