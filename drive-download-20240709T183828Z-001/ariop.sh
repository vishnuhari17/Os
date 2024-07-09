echo "Enter the 2 numbers"
read a
read b
echo "Enter the operation"
read op
#((result=$a$op$b))
#echo $result
if [ $op = '+' ]
then
	echo "result: $((a+b))"
else if [ $op = '-' ]
then
	echo "result: $((a-b))"
else if [ $op = '*' ]
then
	echo "result: $((a*b))"
else if [ $op = '/' ]
then
	echo "result: $((a/b))"
fi
fi
fi
fi
