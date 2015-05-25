ifneq ($(KERNELRELEASE),)
	obj-m	:=set_irq_handler.o tasklet_hi_schedule.o
else
	PWD	:=$(shell pwd)
	KVER	:=$(shell uname -r)
	KDIR	:=/lib/modules/$(KVER)/build/
default:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	-rm -rf *.mod.c .*.cmd *.ko *.o *.mod.c \
		modules.order Module.symvers
endif
