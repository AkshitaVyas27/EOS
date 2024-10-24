#!/bin/bash

echo "Enter a number"
read num

if [ $num -gt 0 ]
then 
	echo "Number is positive"
elif [ $num -lt 0 ]
then 
	echo "Number is negative"
else
	echo "Entered number is zero"
fi
