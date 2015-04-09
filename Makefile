ifneq ($(KERNELRELEASE),)
obj-m	+= mymodule.o
else
PWD	:=$(shell pwd)
KVER	:=$(shell uname -r)
KDIR	:=/lib/modules/$(KVER)/build
all:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	rm -rf *.o *.mod.c *.ko *.symvers *.order *.markers *.~ .*.cmd
endif
