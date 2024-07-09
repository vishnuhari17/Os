#armstrong
echo "Enter a number"
read num
dig_cnt=0
n=$num
sum=0
while [ $n -gt 0 ]
do
    n=$((n/10))
    dig_count=$((dig_count+1))
done
#echo "$dig_count digit number"
n=$num
while [ $n -gt 0 ]
do
    dig=$((n%10))
    pow=$((dig**dig_count))
    sum=$((sum+pow))
    n=$((n/10))
done
if [ $sum -eq $num ]; then
    echo "$num is armstrong number"
else
    echo "Not an Armstrong number"
fi