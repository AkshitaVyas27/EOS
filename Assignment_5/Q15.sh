#!/bin/bash

echo "Enter the name of the first file"
read path1

echo "Enter the name of the second file"
read path2


rev $path1 > $path2

#rev $path1 | cat > $path2

echo "Checking if the execution was successful"

echo "New content of file 2 is"
cat $path2
