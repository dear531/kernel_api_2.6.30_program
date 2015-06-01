ifneq ($(KERNELRELEASE),)
	obj-m	:=set_irq_handler.o tasklet_hi_schedule.o \
		  __tasklet_schedule.o disable_irq_nosync.o \
		  disable_irq_wake.o free_irq.o \
		  kstat_irqs_cpu.o remove_irq.o \
		  request_irq.o request_threaded_irq.o \
		  set_irq_chained_handler.o set_irq_chip.o \
		  set_irq_chip_data.o set_irq_type.o \
		  set_irq_wake.o setup_irq.o \
		  tasklet_disable.o tasklet_disable_nosync.o \
		  tasklet_kill.o tasklet_trylock_unlock.o
else
	PWD	:=$(shell pwd)
	KVER	:=$(shell uname -r)
	KDIR	:=/lib/modules/$(KVER)/build/
default:
	$(MAKE) -C $(KDIR) M=$(PWD)
clean:
	-rm -rf *.mod.c .*.cmd *.ko *.o *.mod.c \
		modules.order Module.symvers Module.markers
endif
