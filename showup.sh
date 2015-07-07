#!/bin/bash

while :
do
	if [ -z "$(ps | grep "AboutClient" | awk '{print $1}')" ];then
		sudo wall -n broadcast.message
		/home/vedams/uid-versions/uid-basic-v0.1/run.sh 'start'
	fi
done
