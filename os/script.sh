echo "Enter the lower limit:"
read a
echo "Enter the upper limit:"
read b
for ((i=a; i<=b; i++))
do
    f=1
    for ((j=2; j<i; j++))
    do
        if ((i%j == 0))
        then
            f=0
            break
        fi
    done
    if ((f==1))
    then
        echo "$i"
    fi
done

