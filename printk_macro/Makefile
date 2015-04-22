ifneq ($(KERNELRELEASE),)
	obj-m	:=printk_macro.o
else
	PWD	:=$(shell pwd)
	KVER	:=$(shell uname -r)
	KDIR	:=/lib/modules/$(KVER)/build/
default:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	-rm -rf *.o *.cmd .*cmd *.ko modules.order  Module.symvers *.mod.c
endif
