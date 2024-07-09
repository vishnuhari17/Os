echo "Enter a limit"
read lim
a=0
b=1
echo "The sequence is "
echo -n "$a "
echo -n "$b "
i=2
while [ $i -lt $lim ]
do 
	c=$((a+b))
	echo -n "$c "
	a=$b
	b=$c
	i=$((i+1))
done
