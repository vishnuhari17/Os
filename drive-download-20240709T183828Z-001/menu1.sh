echo "1--add  2--sub  3--mul 4--div 5--mod"
read choice
case $choice in
1)echo "Enter a and b"
read a
read b
s=$(echo "scale=2;($a+$b)"|bc)
echo "$a+$b=$s"
;;
2)echo "Enter a and b"
read a
read b
s=$(echo "scale=2;($a-$b)"|bc)
echo "$a-$b=$s"
;;
3)echo "Enter a and b"
read a
read b
s=$(echo "scale=2;($a*$b)"|bc)
echo "$a*$b=$s"
;;
4)echo "Enter a and b"
read a
read b
s=$(echo "scale=2;($a/$b)"|bc)
echo "$a/$b=$s"
;;
5)echo "Enter a and b"
read a
read b
s=$((a%b))
echo "$a%$b=$s"
;;
*)echo "INVALID"
;;
esac


`1--add  2--sub  3--mul 4--div 5--mod
5
Enter a and b
8
3
8%3=2`

