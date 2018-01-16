#!/bin/bash

gcc parse.c
echo start > output_1
while [ true ]; do
	rm output_1
	hcitool scan > output
	./a.out
	if [ -s output_1 ]
	then
		echo found
		cd /sys/class/gpio
		echo 12 > export
		cd gpio12
		echo in > direction
		while [ true ]; do
			#output = $(cat value)
			if [ $(cat value) -eq 1 ]
			then
				echo Ready to light LED
			else
				echo distance too far away
			fi
		done
	else
		echo not found
	fi
done



