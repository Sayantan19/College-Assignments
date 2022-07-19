#drop the lines that are matched with a given word entered by teh user

echo "Enter the file name"
read file
echo "Enter the word to be checked"
read word
grep -v -i $word $file
