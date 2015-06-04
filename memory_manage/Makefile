ifneq ($(KERNELRELEASE),)
	obj-m	:=__get_free_pages.o __get_vm_area.o \
		  __krealloc.o struct_print.o refrence.o
else
	PWD	:=$(shell pwd)
	KVER	:=$(shell uname -r)
	KDIR	:=/lib/modules/$(KVER)/build
default:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	-rm -rf *.o .*.cmd.c *.ko .*.cmd *.mod.c \
	modules.order Module.symvers
endif
