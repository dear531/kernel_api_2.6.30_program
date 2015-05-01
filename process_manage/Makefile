ifneq ($(KERNELRELEASE),)
	obj-m	:=task_pid_nr_ns.o find_get_pid.o
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
