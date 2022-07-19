#to find last modified time of a file

echo "Enter the file name"
read file
if [ -f $file ]
then 
    echo "Last modified: "$(stat --format="%y" $file)
else
    echo "Does not exist"
fi