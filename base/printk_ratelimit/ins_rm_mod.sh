#!/bin/bash
for ((i = 0; i < 20; i++))
do
	insmod printk_ratelimit.ko
	rmmod printk_ratelimit
done
