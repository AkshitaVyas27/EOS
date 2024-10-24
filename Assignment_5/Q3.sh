#!/bin/bash


echo "Enter your file path"
read path

if [ -f $path ]
then 
	echo "The entered path is a normal file"
	ls -l -h $path
elif [ -d $path ]
then
	echo "The entered path is a directory"
	ls $path
else
	echo "You've entered invalid path"
fi



