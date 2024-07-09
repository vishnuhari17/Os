#Write a shell script to convert temperature from Celsius to Fahrenheit.
echo "Enter temperature in celcius"
read cel
f=$(echo "scale=2;($cel*9/5+32)"|bc)
echo "$cel in farenheit: $f"




Enter temperature in celcius
32
32 in farenheit: 89

