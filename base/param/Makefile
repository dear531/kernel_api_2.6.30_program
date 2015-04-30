ifneq ($(KERNELRELEASE),)
	obj-m	:=param.o
else
	KVER	:=$(shell uname -r)
	KDIR	:=/lib/modules/$(KVER)/build
	PWD	:=$(shell pwd)
default:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	-rm -rf *.o *.ko *.mod.c *.cmd .*.cmd *.order *.symvers
endif
