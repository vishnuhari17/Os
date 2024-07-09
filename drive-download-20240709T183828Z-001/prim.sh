echo "Enter a number?"
read n
f=2
while [ $n -gt $f ]
do
    if [ $((n%f)) -eq 0 ]; then
        echo "Not prime"
        exit
    fi
    f=$((f+1))
done
echo "Prime"

