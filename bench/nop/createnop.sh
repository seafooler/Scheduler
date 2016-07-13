#!/bin/bash
#Program:
#	This script will create nopcfs whose runtime is 1s, 2s,..., 100s
#History:
#2016/07/12	Seafooler	First release

# 1.insert nop to the assembly file
for((i=0;i<100;i++));do
{
	sed '/$9999999/r nop.txt' $i"snopcfs.s" > $((i+1))"snopcfs.s"
}
done

# 2.compile the assembly file to the executable file
for((i=0;i<100;i++));do
{
	gcc $((i+1))"snopcfs.s" -o  $((i+1))"snopcfs" 
}
done


