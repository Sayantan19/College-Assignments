read a
s=0
while [ $a -gt 0 ]
do
	x=`expr $a % 10`
	s=`expr $s + $x`
	a=`expr $a / 10`
done

echo $s


	
	
	
