echo ' Enter the numbers '
read a
read b
echo ' A for Add '
echo ' S for Subtract '
echo ' M for Multiply '
echo ' D for Divide '
read x
case "$x" in
   "A") c=`expr $a + $b` 
   ;;
   "S") c=`expr $a - $b` 
   ;;
   "M") c=$( echo "$a * $b" | bc ) 
   ;;
   "D") c=$( echo " $a / $b" | bc ) 
   ;;
esac
echo $c

