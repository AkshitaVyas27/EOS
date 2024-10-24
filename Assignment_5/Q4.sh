#!/bin/bash

echo -n -e "Enter your number"
read num
flag=0
i=2

while [ $i -lt $num ]
do
	res=`expr $num % $i`
	if [ $res -eq 0 ]
	then
	flag=1
	fi
	i=`expr $i + 1`
done

if [ $flag -eq 0 ]
then 
	echo -e -n "Number is a prime number"
else
	echo -e -n "Number is not a prime number"
fi
