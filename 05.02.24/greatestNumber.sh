echo "Enter two numbers: "
read numOne
read numTwo

if [ $numOne -eq $numTwo ]
then
echo "Both are equal"
elif [ $numOne -gt $numTwo ]
then 
echo "Greatest number is: $numOne"
else
echo "Greatest number is: $numTwo"
fi

	

