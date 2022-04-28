read a
flag=0
s=0
i=1
while [ $i -le $a ]
do
	x=`expr $a % $i`
	if [ $x -eq 0 ]
	then
		s=`expr $s + 1`
	fi
	i=`expr $i + 1`
done
if [ $s -eq 2 ]
then
	echo "Prime"
else
	echo "Not Prime"
fi
