#!/bin/bash
let x=0
while [[ $x -lt 100 ]]; do
	sudo insmod myQueue.ko
	sleep 1
	sudo chmod 666 /dev/myQueue*
	sleep 1
	sudo rmmod myQueue.ko
done
