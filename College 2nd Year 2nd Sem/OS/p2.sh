read a
if [ $(echo -n "$a" | wc -c) -lt 10 ]
then
	echo "Less than 10 characters"
else
	echo "Valid"
fi
