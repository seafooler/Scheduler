#!/bin/bash
#Program:
#	This script will create tasks whose runtime is 1s, 2s,..., ns
#History:
#2016/07/12	Seafooler	First release
#2016/07/15	Seafooler	Second release

# number of tasks
n=100

# 1.insert nop to the assembly file
for((i=0;i<n;i++));do
{
	sed '/$9999999/r nop.txt' $i"stask.s" > $((i+1))"stask.s"
}
done

# 2.modify the respondding runtime in the assembly file
for((i=1; i<=n; i++));do
{
	sed -i 's/$0, -116/$'"$i"', -116/' $i"stask.s"
}
done

# 3.compile the assembly file to the executable file
for((i=1;i<=n;i++));do
{
	gcc $i"stask.s" -o  $i"stask" 
}
done


