read a
read b
flag=0
s=0
i=1
if [ $a -gt $b ]
then
	x=$a
else
	x=$b
fi
while [ $i -le $x ]
do
	x1=`expr $a % $i`
	x2=`expr $b % $i`
	if [ $x1 -eq 0 ]
	then
		if [ $x2 -eq 0 ]
		then 
			s=`expr $s + 1`
		fi
	fi
	i=`expr $i + 1`
done
if [ $s -eq 1 ]
then
	echo "Prime"
else
	echo "Not Prime"
fi
