echo ' Enter the Marks '
read a
if [ $a -gt 90 -a $a -le 100 ]
then 
	echo "O"
elif [ $a -gt 80 -a $a -le 89 ]
then 
	echo "E"
elif [ $a -gt 70 -a $a -le 79 ]
then 
	echo "A"
elif [ $a -gt 60 -a $a -le 69 ]
then 
	echo "B"
elif [ $a -gt 50 -a $a -le 59 ]
then 
	echo "C"
else
	echo "Fail"
fi
