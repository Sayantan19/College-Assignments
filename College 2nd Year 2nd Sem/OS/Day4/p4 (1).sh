
read -p "Enter the file name: " filename
while read line
do
echo $line
if [[ $line > "90" && $line < "100" ]]
then 
	echo "O"
elif [[ $line > "80" && $line < "89" ]]
then 
	echo "E"
elif [[ $line > 70 && $line < 79 ]]
then 
	echo "A"
elif [[ $line > 60 && $line < 69 ]]
then 
	echo "B"
elif [[ $line > 50 && $line < 59 ]]
then 
	echo "C"
elif [[ $line < 50 ]]
then
	echo "Fail"
fi
done < $filename
