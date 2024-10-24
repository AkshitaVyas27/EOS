#!/bin/bash

echo "Enter the basic salary"
read sal

hra=`echo "scale=3; $sal / 5" | bc`
da=`echo "scale=3; $sal *2 / 5" | bc`
gsal=`echo "scale=3; $sal + $hra + $da" | bc`
echo "Gross salary:$gsal"
