#Write a shell script program to find the largest and smallest of three numbers.
echo "Enter first number"
read a
echo "Enter second number"
read b
echo "Enter third number"
read c
if [ $a -gt $b ]; then
	if [ $a -gt $c ]; then
		l=$a
		if [ $b -gt $c ]; then
			s=$c
		else
			s=$b
		fi
	else
		l=$c
		s=$b
	fi
else
	if [ $b -gt $c ]; then
		l=$b
		if [ $a -gt $c ]; then
			s=$c
		else
			s=$a
		fi
	else
		l=$c
		if [ $a -gt $b ]; then
			s=$b
		else
			s=$a
		fi
	fi
fi
echo "The largest number is $l and smallest is $s"



 



Enter first number
6
Enter second number
4
Enter third number
9
The largest number is 9 and smallest is 4	
