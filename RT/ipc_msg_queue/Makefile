# this is a minimal makefile for demo purposes, keep it that way...
obj-m:=myQueue.o
myQueue-objs:=main.o
V?=0
KDIR?=/lib/modules/$(shell uname -r)/build
# in an embedded system:
#KDIR:=[where the system maker gave me kernel headers+makefile or the kernel itself which has a makefile]
#ARCH:=arm
#CROSS_COMPILE:=[path+common prefix to where the toolchain is]
# You could also use W=2 and W=3 for more warnings but most kernel headers
# fail those...
W?=1
.PHONY: modules
modules:
	$(MAKE) -C $(KDIR) M=$(CURDIR) V=$(V) W=$(W) modules
.PHONY: clean
clean:
	$(MAKE) -C $(KDIR) M=$(CURDIR) V=$(V) clean
	rm -f *.stamp
.PHONY: insmod
insmod:
	sudo insmod myQueue.ko
	sleep 1
	sudo chmod 666 /dev/myQueue*
.PHONY: rmmod
rmmod:
	sudo rmmod myQueue.ko
.PHONY: test1
test1:
	for number in $$(seq 1 100);\
	do \
	sudo insmod myQueue.ko ;\
	sleep 1 ;\
	sudo chmod 666 /dev/myQueue*;\
	(number=number+1);\
	sudo rmmod myQueue;\
	echo $$number;\
	done
test2: test2.c
	gcc -o2 -o $@ $< -pthread
.PHONY: prog
prog:
	sudo insmod myQueue.ko
	sleep 1
	sudo chmod 666 /dev/myQueue*
	sleep 1
	sudo rmmod myQueue.ko
test0:
	gcc -o2 put.c -o put
	gcc -o2 get.c -o get
	gcc -o2 test2.c -o test2 -pthread
	gcc -o2 test3.c -o test3 -pthread
	gcc -o2 test4.c -o test4 -pthread



