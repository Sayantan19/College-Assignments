read rows
for((i=1; $i<=$rows; i=$i+1))
do
  for((j=1; $j<=$rows - $i; j=$j+1))
  do
    echo -n "  "
  done
  for((j=1; $j<=2*$i - 1; j=$j+1))
  do
    echo -n "* "
  done
  echo
done
