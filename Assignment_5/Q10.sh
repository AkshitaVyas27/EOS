#!/bin/bash

echo "Enter the number upto which you want the fibonacci series to be printed"
read num

a=1
b=1
c=0
i=1
while [ $i -le $num ]
do
	echo -n -e "  $a"
	c=`expr $a + $b`
	a=$b
	b=$c
	i=`expr $i + 1`
done
