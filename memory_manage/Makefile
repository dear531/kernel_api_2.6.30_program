ifneq ($(KERNELRELEASE),)
	obj-m	:=__get_free_pages.o __get_vm_area.o \
		  __krealloc.o struct_print.o refrence.o \
		  alloc_pages.o alloc_pages_exact.o \
		  alloc_vm_area.o do_brk.o do_mmap.o \
		  do_mmap_pgoff.o do_munmap.o find_vma.o \
		  find_vma_intersection.o get_unmapped_area.o
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
