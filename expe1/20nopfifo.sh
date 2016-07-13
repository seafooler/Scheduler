#!/bin/bash
#Program:
#	This script will start 20 nopfifo processes
#History:
#2016/07/11	Seafooler	First release

for((i=0;i<20;i++));do
{
	/home/seafooler/sched/expe2/nopfifo
}&
done

