#Write a shell script program to find the largest and smallest of two numbers.

echo -n "Enter the first number: "
read a
echo -n "Enter the second number: "
read b

if [ $a -gt $b ]; then
    echo "$a is the largest and $b is the smallest"
elif [ $b -gt $a ]; then 
    echo "$b is the largest and $a is the smallest"
else
    echo "Both numbers are equal"
fi

