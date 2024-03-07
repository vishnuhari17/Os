#Write a shell script program to find the average of n numbers.

echo -n "Enter the value of n: "
read n

sum=0
count=0

echo "Enter $n numbers:"

for (( i=1; i<=$n; i++ )); do
    echo -n "Enter number $i: "
    read num
    sum=$((sum + num))
    count=$((count + 1))
done

average=$(echo "scale=2; $sum / $count" | bc)

echo "The average of the $n numbers is: $average"


#Output :
#Enter the value of n: 5
#Enter 5 numbers:
#Enter number 1: 28
#Enter number 2: 39
#Enter number 3: 10
#Enter number 4: 4
#Enter number 5: 58
#The average of the 5 numbers is: 27.80

