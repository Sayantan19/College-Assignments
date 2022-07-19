read user

echo

echo "Validating the $user ..."

if [ `grep -c $user /etc/passwd` -eq 0 ]
then
echo
echo "ERROR : PLEASE ENTER A VALID USERNAME."
echo "Exiting ..." 
else
echo "Valid user "
fi