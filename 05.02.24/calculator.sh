while true
do
    echo -e "Choose operation\n1.Addition\n2.Subtraction\n3.Multiplication\n4.Division\n5.Exit"
    read operation

    if [ $operation -eq 5 ]
    then
        break
    fi

    echo "Enter two numbers"
    read numone
    read numtwo

    case $operation in
        1)
            echo "Sum is $((numone + numtwo))"
            ;;
        2)
            echo "Difference is $((numone - numtwo))"
            ;;
        3)
            echo "Product is $((numone * numtwo))"
            ;;
        4)
            echo "Quotient is $((numone / numtwo))"
            ;;
        *)
            echo "Invalid choice"
            ;;
    esac
done

