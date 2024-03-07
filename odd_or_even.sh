#Write a shell script program to check whether a given number is odd or even.

echo -n "Enter a number: "
read number

if (( number % 2 == 0 )); then
    echo "$number is even."
else
    echo "$number is odd."
fi

#Output :
#Enter a number: 5
#5 is odd.

