#!/bin/bash

echo "Enter the file name"
read path

if [ -e $path ]
then 
	echo "Info about entered file is"
	ls -l $path
else
	echo "File doesn't exist"
fi
