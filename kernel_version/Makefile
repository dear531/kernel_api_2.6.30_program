ifneq ($(KERNELRELEASE),)
	obj-m	:=kernel_version.o
else
	KVER	:=$(shell uname -r)
	KDIR	:=/lib/modules/$(KVER)/build/
	PWD	:=$(shell pwd)
default:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	-rm -rf *.o *.ko .*.cmd *.cmd *.~ *.mod.c  modules.order  Module.symvers
endif
