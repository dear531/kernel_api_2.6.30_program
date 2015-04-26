#!/bin/bash
if [ "$1" == "-r" ];
then
	rmmod symbol_get
	rmmod sym_a
else
	insmod sym_a.ko
	insmod symbol_get.ko
fi

