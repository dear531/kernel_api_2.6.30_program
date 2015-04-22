default:
	echo "please choose userspace or kernelspace for target"
vpath pdebug.h .
ifneq ($(KERNELRELEASE),)
	obj-m	:=kernel_print.o
else
	PWD	:=$(shell pwd)
	KVER	:=$(shell uname -r)
	KDIR	:=/lib/modules/$(KVER)/build
kernelspcace:
	$(MAKE) -C $(KDIR) M=$(PWD)
endif
userspace:userspace_print.c
	cc $^ -o $@
clean:
	-rm -rf *.o *.ko *mod.c a.out Module.symvers modules.order \
	.*.cmd userspace
