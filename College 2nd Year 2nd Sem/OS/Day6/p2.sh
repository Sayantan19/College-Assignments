echo "Enter the line"
read l
echo "Enter the character."
read a
x=`echo $l | cut -d ' ' -f 1-4 `
w=`echo $l | cut -d ' ' -f 5`
y=`echo $w | wc -c | echo ${w:(-(y - 4))}`
z=`echo $l | cut -d ' ' -f 6`
echo -n $x' '$a$a$a$a$y' '$z
