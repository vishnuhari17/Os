#Write a shell script program to find the largest and smallest of three numbers.

echo -n "Enter the first number: "
read a
echo -n "Enter the second number: "
read b
echo -n "Enter the third number: "
read c

largest=$a
smallest=$a

if [ $b -gt $largest ]; then
    largest=$b
fi

if [ $c -gt $largest ]; then
    largest=$c
fi

if [ $b -lt $smallest ]; then
    smallest=$b
fi

if [ $c -lt $smallest ]; then
    smallest=$c
fi

echo "The largest number is $largest and the smallest number is $smallest"


#Output :
#Enter the first number: 5
#Enter the second number: 10
#Enter the third number: 2
#The largest number is 10 and the smallest number is 2

