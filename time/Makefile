ifneq ($(KERNELRELEASE),)
	obj-m	:=__round_jiffies.o __round_jiffies_relative.o \
		  __round_jiffies_up.o __round_jiffies_up_relative.o \
		  current_kernel_time.o timer.o do_gettimeofday.o \
		  get_seconds.o getnstimeofday.o \
		  init_timer_deferrable.o init_timer_deferrable_key.o \
		  init_timer_key.o mktime.o mktime.o mod_timer.o \
		  ns_to_timespec.o ns_to_timeval.o \
		  set_normalized_timespec.o timespec_compare.o \
		  timespec_sub.o
else
	PWD	:=$(shell pwd)
	KVER	:=$(shell uname -r)
	KDIR	:=/lib/modules/$(KVER)/build/
default:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	-rm -rf *.o *.ko .*.cmd.c .*.cmd *.mod.c\
		.tmp_versions modules.order Module.symvers
endif
