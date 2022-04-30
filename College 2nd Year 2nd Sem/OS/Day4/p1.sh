read a
read b
read c
if [ $a -gt $b -a $a -gt $c ]
then
	echo $a ' is the greatest'
elif [ $b -gt $a -a $b -gt $c ]
then
	echo $b ' is the greatest'
else
	echo $c ' is the greatest'
fi

