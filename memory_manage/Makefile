ifneq ($(KERNELRELEASE),)
	obj-m	:=__get_free_pages.o __get_vm_area.o \
		  __krealloc.o struct_print.o refrence.o \
		  alloc_pages.o alloc_pages_exact.o \
		  alloc_vm_area.o do_brk.o do_mmap.o \
		  do_mmap_pgoff.o do_munmap.o find_vma.o \
		  find_vma_intersection.o get_unmapped_area.o \
		  get_user_pages.o get_user_pages_fast.o \
		  get_vm_area_size.o get_zeroed_page.o \
		  kcalloc.o kmalloc.o kmem_cache_alloc.o \
		  kmemdup.o krealloc.o ksize.o kstrdup.o \
		  kstrndup.o kzalloc.o memdup_user.o \
		  mempool_alloc.o mempool_alloc_pages.o \
		  mempool_alloc_slab.o mempool_create.o \
		  mempool_kmalloc.o mempool_kzalloc.o \
		  mempool_resize.o nr_free_buffer_pages.o \
		  page_address.o page_cache_get.o
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
