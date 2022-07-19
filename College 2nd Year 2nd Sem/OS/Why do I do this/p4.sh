# go to the third letter of the third word and replace it with the letter 'p'

echo "Enter a line"
read line
w=$(echo $line | cut -d ' ' -f -2)
x=$(echo $line | cut -d ' ' -f 3-3 | cut -c -2)
y=$(echo $line | cut -d ' ' -f 3-3 | cut -c 4-)
z=$(echo $line | cut -d ' ' -f 4-)
echo $w" "$x"p"$y" "$z