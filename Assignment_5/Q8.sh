#!bin/bash

echo "Enter the number"
read num
i=1
while [ $i -le 10 ]
do
	res=`expr $num \* $i`
	echo "$res"
	i=`expr $i + 1`
done
