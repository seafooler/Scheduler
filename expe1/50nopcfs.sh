#!/bin/bash
#Program:
#	This script will start 50 nopcfs processes
#History:
#2016/07/11	Seafooler	First release

i=0
while [ "$i" != "50" ]
do
{
	/home/seafooler/sched/nopcfs
}&
done

