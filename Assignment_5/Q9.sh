#!/bin/bash

echo "Enter a number"
read num
i=1
res=1
while [ $i -le $num ]
do
	res=`expr $res \* $i`
	i=`expr $i + 1`
done

echo "Factorial of the number is: $res"
