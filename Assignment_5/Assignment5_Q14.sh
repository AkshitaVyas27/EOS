#!/bin/bash

echo "Files with ececutable permission are"

for file in *
do 
	if [ -f $file ]
	then
		if [ -x $file ]
		then 
			ls -l $file
		fi
	fi
done
