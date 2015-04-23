ifneq ($(KERNELRELEASE),)
	obj-m	:= printk_ratelimit.o
else
	PWD	:=$(shell pwd)
	KVER	:=$(shell uname -r)
	KDIR	:=/lib/modules/$(KVER)/build/
default:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	-rm -rf *.o a.out *.cmd .*.cmd *.mod.c *.ko \
		modules.order  Module.symvers .tmp_versions
endif
