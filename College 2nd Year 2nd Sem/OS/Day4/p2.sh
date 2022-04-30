s=0
i=1
while [ $i -le 7 ]
do
	read d
	echo 'Date: ' $d
	read temp
	s=`expr $temp + $s`
	i=`expr $i + 1`
done
avg=`expr $s / 7`
echo 'Average temperature: '$avg
