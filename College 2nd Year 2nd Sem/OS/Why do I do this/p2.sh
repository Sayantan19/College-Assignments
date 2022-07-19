#check whether the given string has less than 10 characters or not
echo "Enter a string"
read str
letters=$(echo $str | wc -c)
if [ $letters -lt 10 ]
then 
    echo "Less than 10 characters"
else
    echo "More than or equal to 10 characters"
fi