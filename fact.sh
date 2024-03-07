#Write a program to find the factorial of a number.

echo "Enter a number"
read n
f=1
q=$n
while [ $n -gt 1 ]
do
    f=$((f*n))
    n=$((n-1))
done
echo "factorial of $q: $f"
