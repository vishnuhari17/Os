echo "1--Area of Circle  2--Circumference  3--Area of Rectangle 4--Area of square"
read choice
case $choice in
1)echo "Enter radius"
read r
a=$(echo "scale=2;(3.14*$r*$r)"|bc)
echo "Area of circle is: $a"
;;
2)echo "Enter radius"
read r
a=$(echo "scale=2;(6.28*$r)"|bc)
echo "circumference is: $a"
;;
3)echo "Enter l and b"
read l
read b
a=$((l*b))
echo "Area of rectangle is: $a"
;;
4)echo "Enter side"
read s
a=$((s*s))
echo "Area of square is: $a"
;;
*)echo "INVALID"
;;
esac




1--Area of Circle  2--Circumference  3--Area of Rectangle 4--Area of square
3
Enter l and b
6
10
Area of rectangle is: 60
