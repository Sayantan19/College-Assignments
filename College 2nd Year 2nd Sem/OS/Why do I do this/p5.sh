#to rewrite file in specific format
#1 all caps
#2 all small
#3 cap to small and vice versa

#also count the number of characters without the spaces
echo "Enter the file name"
read file
cat $file | tr "[A-Z]" "[a-z]" > file1.txt
cat $file | tr "[a-z]" "[A-Z]" > file2.txt
cat $file | tr "[A-Z][a-z]" "[a-z][A-Z]" > file3.txt
x=$(cat $file | tr -d " " | wc -c)
echo "All caps:"
cat file1.txt
echo "All small:"
cat file2.txt
echo "Mixed:"
cat file3.txt
echo "Characters: "$x