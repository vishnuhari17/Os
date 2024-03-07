#Write a shell script program to find the difference of 2 numbers.

echo -n "Enter the first no  : "
read a
echo -n "Enter the second no : "
read b
diff=$((a-b)) 
echo "The difference between first and second no is $diff"

