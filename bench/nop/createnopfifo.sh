#!/bin/bash
#Program:
#	This script will create nopfifo whose runtime is 1s, 2s,..., 100s,
#	nopfifs is used to test if the process's runtime is exactly 1s, 2s,..., 100s
#History:
#2016/07/12	Seafooler	First release

# 1.insert nop to the assembly file
for((i=0;i<100;i++));do
{
	sed '/$9999999/r nop.txt' $i"snopfifo.s" > $((i+1))"snopfifo.s"
}
done

# 2.compile the assembly file to the executable file
for((i=0;i<100;i++));do
{
	gcc $((i+1))"snopfifo.s" -o  $((i+1))"snopfifo" 
}
done


