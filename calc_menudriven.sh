
while true; do
    echo "Menu:"
    echo "1. Addition"
    echo "2. Subtraction"
    echo "3. Multiplication"
    echo "4. Division"
    echo "5. Modulus"
    echo "6. Exit"
    echo -n "Enter your choice: "
    read choice
	echo -n "Enter the first number: "
    read num1
    echo -n "Enter the second number: "
    read num2
    case $choice in
        1)
            result=$((num1 + num2)) ;;
        2)
            result=$((num1 - num2)) ;;
        3)
            result=$((num1 * num2)) ;;
        4)
            if [ $num2 -eq 0 ]; then
        		echo "Error: Division by zero!"
    		else
        		result=$(echo "scale=2; $num1 / $num2" | bc)
        	fi ;;
        5)
            if [ $num2 -eq 0 ]; then
        		echo "Error: Modulus by zero!"
    		else
        		result=$((num1 % num2))
        	fi ;;
        6)
            echo "Exiting program."
            exit ;;
        *)
            echo "Invalid choice. Please enter a number between 1 and 6." ;;
    esac
    echo "Result: $result"
done

