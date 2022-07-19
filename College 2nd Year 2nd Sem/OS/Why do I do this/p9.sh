#Write a shell program to take the name of a file from the user. If the file presents in the directory, removed all the numerical values from the file and tell the total number of vowels in the same file.
echo "Enter a filename"
read file
if [ -f $file ]
then
    cat $file | tr -d [:digit:]
else
    echo "Does not exist"
fi

vow=$(cat $file | grep -o -i "[aeiou]"| wc -l)
echo $vow
