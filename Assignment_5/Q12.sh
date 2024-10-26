#!/bin/bash

echo "start"


echo " $1 "
if [ -e $1  ]
then
	t=`stat -c %y $1`
	echo "time  : $t "
else
	echo "file doesnt exist"
fi 
