#Write a shell script program to find the sum of n natural numbers.

echo -n "Enter the value of n: "
read n

sum=0
i=1

while [ $i -le $n ]; do
    sum=$((sum + i))
    i=$((i + 1))
done

echo "The sum of the first $n natural numbers is: $sum"

#Output :
#Enter the value of n: 10
#The sum of the first 10 natural numbers is: 55

