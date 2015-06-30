ifneq ($(KERNELRELEASE),)
	obj-m	:=atomic_add.o atomic_add_negative.o
else
	PWD	:=$(shell pwd)
	KVER	:=$(shell uname -r)
	KDIR	:=/lib/modules/$(KVER)/build/
default:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	-rm -rf *.o *.ko *.mod.c .*.cmd \
		modules.order Module.symvers .tmp_versions
endif
