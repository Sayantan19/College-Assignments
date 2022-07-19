#Sort the files in a directory based on their size

echo "Enter the name of the directory"
read dir
cd $dir
ls -l > b.txt
cat b.txt
cut -d " " -f 5,9 b.txt > c.txt 
sort -n -r c.txt

grep "^-rwx" b.txt
