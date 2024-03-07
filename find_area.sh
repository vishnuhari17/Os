#Write a shell script to perform the following task according to user choice menu.
#1. Area of Circle
#2. Circumference of Circle
#3. Area of Rectangle
#4. Area of Square

calculate_circle_area() {
    echo -n "Enter the radius of the circle: "
    read radius
    area=$(echo "scale=2; 3.14 * $radius * $radius" | bc)
    echo "The area of the circle is: $area"
}


calculate_circle_circumference() {
    echo -n "Enter the radius of the circle: "
    read radius
    circumference=$(echo "scale=2; 2 * 3.14 * $radius" | bc)
    echo "The circumference of the circle is: $circumference"
}


calculate_rectangle_area() {
    echo -n "Enter the length of the rectangle: "
    read length
    echo -n "Enter the width of the rectangle: "
    read width
    area=$((length * width))
    echo "The area of the rectangle is: $area"
}


calculate_square_area() {
    echo -n "Enter the side length of the square: "
    read side
    area=$((side * side))
    echo "The area of the square is: $area"
}



while true; do
    echo "Menu:"
    echo "1. Area of Circle"
    echo "2. Circumference of Circle"
    echo "3. Area of Rectangle"
    echo "4. Area of Square"
    echo "5. Exit"
    echo -n "Enter your choice: "
    read choice

    case $choice in
        1)
            calculate_circle_area ;;
        2)
            calculate_circle_circumference ;;
        3)
            calculate_rectangle_area ;;
        4)
            calculate_square_area ;;
        5)
            echo "Exiting program."
            exit ;;
        *)
            echo "Invalid choice. Please enter a number between 1 and 5." ;;
    esac
    echo
done

#Output :
#Menu:
#1. Area of Circle
#2. Circumference of Circle
#3. Area of Rectangle
#4. Area of Square
#5. Exit
#Enter your choice: 1
#Enter the radius of the circle: 2
#The area of the circle is: 12.56
#
#Menu:
#1. Area of Circle
#2. Circumference of Circle
#3. Area of Rectangle
#4. Area of Square
#5. Exit
#Enter your choice: 2
#Enter the radius of the circle: 5
#The circumference of the circle is: 31.40
#
#Menu:
#1. Area of Circle
#2. Circumference of Circle
#3. Area of Rectangle
#4. Area of Square
#5. Exit
#Enter your choice: 3
#Enter the length of the rectangle: 2
#Enter the width of the rectangle: 3
#The area of the rectangle is: 6
#
#Menu:
#1. Area of Circle
#2. Circumference of Circle
#3. Area of Rectangle
#4. Area of Square
#5. Exit
#Enter your choice: 4
#Enter the side length of the square: 7
#The area of the square is: 49
#
#Menu:
#1. Area of Circle
#2. Circumference of Circle
#3. Area of Rectangle
#4. Area of Square
#5. Exit
#Enter your choice: 5
#Exiting program.

