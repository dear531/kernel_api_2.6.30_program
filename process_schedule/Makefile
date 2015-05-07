ifneq ($(KERNELRELEASE),)
	obj-m	:=wake_up.o
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
