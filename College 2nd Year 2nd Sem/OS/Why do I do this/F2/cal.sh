echo "Enter 2 numbers"
read a
read b
echo "1 for Addition"
echo "2 for Subtraction"
echo "3 for Multiplication"
echo "4 for Division"
echo "Enter your choice: "
read ch
case $ch in
    1) s=$( echo $a + $b" | bc)
            echo $s
    ;;
    2) d=$( echo "$a - $b" | bc)
            echo $d
    ;;
    3) p=$( echo "$a * $b" | bc)
            echo $p
    ;;
    4) q=$( echo "$a / $b" | bc)
			echo $q
	;;
esac