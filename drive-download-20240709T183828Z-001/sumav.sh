#Write a shell script program to find the sum and average of n natural numbers.
echo "Enter the value of n"
read n
i=1
s=0
while [ $le -le $n ]
do
	s=$((s+i))
	i=$((i+1))
done
av=$(echo "scale=2;($s/$n)"|bc)
echo "The sum is $s and average is $av"




`Enter the value of n
6
The sum is 21 and average is 3.50`

