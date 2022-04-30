echo 'Enter basic salary'
read bs
da=`expr 52 / 100 \* $bs`
hra=`expr 15 / 100 \* $bs`
pf=`expr 12 / 100 \* [ $bs + $da ]`
gs=`expr $da + $hra- $pf`
echo "DA: "$da
echo "HRA: "$hra
echo "PF: "$pf
echo "GS: "$gs

