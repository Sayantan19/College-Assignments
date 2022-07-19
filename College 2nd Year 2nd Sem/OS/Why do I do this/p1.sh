#to check the number of vowels and consonants in the given line
echo "Enter the sentence"
read str
vow=$(echo $str | grep -o -i "[aeiou]" | wc -l)
letters=$(echo $str | wc -m)
cons=$(($letters - $vow))
echo "Vowels: " $vow
echo "Consonants: " $cons
