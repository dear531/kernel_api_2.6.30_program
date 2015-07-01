ifneq ($(KERNELRELEASE),)
	obj-m	:=atomic_add.o atomic_add_negative.o \
		  atomic_add_return.o atomic_add_unless.o \
		  atomic_cmpxchg.o atomic_dec.o \
		  atomic_dec_and_test.o atomic_inc_and_test.o \
		  atomic_sub_and_test.o atomic_sub_return.o \
		  down.o down_interruptible.o down_read.o \
		  down_read_trylock.o
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
