obj-m := hello.o

#KRNELDIR=/lib/modules/$(shell uname -r)/build/
KERNELDIR=/usr/src/linux-headers-5.4.0-52-generic/

PWD := $(shell pwd)

default:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KERNELDIR) M=$(PWD) clean