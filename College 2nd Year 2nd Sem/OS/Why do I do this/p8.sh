# take 2 folder as input check which one has more read and write files and by how much
echo "Enter the first folder name"
read f1
echo "Enter the second folder name"
read f2
cd $f1
ls -l >s1.txt
x=$(grep "rw" s1.txt | wc -l)
cd ..
cd $f2
ls -l >s1.txt
y=$(grep "rw" s1.txt | wc -l)
if [ $x -gt $y ]
then 
    echo "Folder 1 has more rw files with "$(($x-$y))" difference"
else
    echo "Folder 2 has more rw files with "$(($y-$x))" difference"
fi