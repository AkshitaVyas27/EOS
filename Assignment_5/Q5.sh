#!/bin/bash

echo -n -e  "Enter number 1"
read num1
echo "Enter number 2"
read num2
echo "Enter number 3"
read num3

if [ $num1 -gt $num2 -a $num1 -gt $num3 ]
then 
	echo -n -e  "$num1 is the greatest number"
elif [ $num2 -gt $num1 -a $num2 -gt $num3 ]
then 
	echo -n -e "$num2 is the greatest number"
else
	echo "$num3 is the greatest number"
fi

