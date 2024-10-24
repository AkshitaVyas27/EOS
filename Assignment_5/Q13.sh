#!/bin/bash

echo "Enter a directory path"
read path

if [ -f $path ]
then
	echo "path is that of a file"
else
	ls -l -a $path
fi
