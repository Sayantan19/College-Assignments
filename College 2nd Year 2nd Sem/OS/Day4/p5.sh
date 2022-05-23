echo 'Enter basic salary'
read bs
da=$( echo "0.52 * $bs" | bc )
hra=$( echo "0.15 * $bs" | bc )
pf=$( echo "0.12 * ( $bs + $da )" | bc )
gs=$( echo "$bs+$da+$hra+$pf" | bc )
ths=$( echo "$bs+$da+$hra-$pf" | bc )
echo "GS: "$gs
echo "THS: "$ths
