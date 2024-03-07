#Write a shell script to convert temperature from Celsius to Fahrenheit.

echo -n "Enter the temperature in Celsius : "
read temp
f=$((temp*9/5+32))
echo "The temperature in Fahrenheit is $f"



