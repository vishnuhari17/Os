#Write a shell script to implement a menu driven calculator with following functions
#1. Addition 2. Subtraction 3. Multiplication 4. Division 5. Modulus


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
    
    case $choice in
        1)
            echo -n "Enter the first number: "
            read num1
            echo -n "Enter the second number: "
            read num2
            result=$((num1 + num2))
            echo "Result: $result" ;;
        2)
            echo -n "Enter the first number: "
            read num1
            echo -n "Enter the second number: "
            read num2
            result=$((num1 - num2))
            echo "Result: $result" ;;
        3)
            echo -n "Enter the first number: "
            read num1
            echo -n "Enter the second number: "
            read num2
            result=$((num1 * num2))
            echo "Result: $result" ;;
        4)
            echo -n "Enter the first number: "
            read num1
            echo -n "Enter the second number: "
            read num2
            if [ $num2 -eq 0 ]; then
                echo "Error: Division by zero!"
            else
                result=$(echo "scale=2; $num1 / $num2" | bc)
                echo "Result: $result"
            fi ;;
        5)
            echo -n "Enter the first number: "
            read num1
            echo -n "Enter the second number: "
            read num2
            if [ $num2 -eq 0 ]; then
                echo "Error: Modulus by zero!"
            else
                result=$((num1 % num2))
                echo "Result: $result"
            fi ;;
        6)
            echo "Exiting program."
            exit ;;
        *)
            echo "Invalid choice. Please enter a number between 1 and 6." ;;
    esac
    echo
done

# Output commented out:
# Menu:
# 1. Addition
# 2. Subtraction
# 3. Multiplication
# 4. Division
# 5. Modulus
# 6. Exit
# Enter your choice: 1
# Enter the first number: 3
# Enter the second number: 4
# Result: 7
# Menu:
# 1. Addition
# 2. Subtraction
# 3. Multiplication
# 4. Division
# 5. Modulus
# 6. Exit
# Enter your choice: 2
# Enter the first number: 3
# Enter the second number: 2
# Result: 1
# Menu:
# 1. Addition
# 2. Subtraction
# 3. Multiplication
# 4. Division
# 5. Modulus
# 6. Exit
# Enter your choice: 3
# Enter the first number: 3
# Enter the second number: 4
# Result: 12
# Menu:
# 1. Addition
# 2. Subtraction
# 3. Multiplication
# 4. Division
# 5. Modulus
# 6. Exit
# Enter your choice: 4
# Enter the first number: 7
# Enter the second number: 2
# Result: 3.50
# Menu:
# 1. Addition
# 2. Subtraction
# 3. Multiplication
# 4. Division
# 5. Modulus
# 6. Exit
# Enter your choice: 5
# Enter the first number: 4
# Enter the second number: 3
# Result: 1
# Menu:
# 1. Addition
# 2. Subtraction
# 3. Multiplication
# 4. Division
# 5. Modulus
# 6. Exit
# Enter your choice: 6
# Exiting the program

