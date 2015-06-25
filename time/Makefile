ifneq ($(KERNELRELEASE),)
	obj-m	:=__round_jiffies.o __round_jiffies_relative.o
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
