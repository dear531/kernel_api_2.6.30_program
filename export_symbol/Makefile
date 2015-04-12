ifneq ($(KERNELRELEASE),)
	obj-m	:=export_symbol.o extern.o
else
	KVER	:=$(shell uname -r)
	KDIR	:=/lib/modules/$(KVER)/build
	PWD	:=$(shell pwd)
defalut:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	-rm -rf *.o *.ko *.cmd .*.cmd *.~ *.mod.c  modules.order Module.symvers
endif
