#!bin/bash

echo -n -e "Enter your choice"
echo -n -e "1. Date 2.Calander 3. ls 4.pwd 5.exit"

read choice
case $choice in
1) date
	;;
2) cal
	;;
3) ls
	;;
4) pwd
	;;
5) exit
	;;
esac


