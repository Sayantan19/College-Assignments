read dividend
read divisor
if [ $divisor == 0 ]
then
	echo 'Cannot be divided'
else
	x=`expr $dividend / $divisor`
	echo $x
fi

