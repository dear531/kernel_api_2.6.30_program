ifneq ($(KERNELRELEASE),)
	obj-m	:=modules_address.o module_ref_addr.o module_text_address.o \
		  print_symbol.o symbol_get.o sym_a.o find_module.o find_symbol.o \
		  module_is_live.o module_put.o module_refcount.o module_state.o \
		  sprint_symbol.o
else
	PWD	:=$(shell pwd)
	KVER	:=$(shell uname -r)
	KDIR	:=/lib/modules/$(KVER)/build
default:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	-rm -rf *.o *.ko *.mod.c .*.cmd \
		modules.order Module.symvers .tmp_versions
endif
