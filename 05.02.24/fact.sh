echo "Enter a number"
read num
fact=1
for((i=num; i>=1; i--))
do
	fact=$((fact * i))
done
echo "factorial of $num is $fact"
