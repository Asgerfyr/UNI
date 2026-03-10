#!/bin/bash


for i in {1..20}; do
    div3=$((i % 3 == 0))
    div5=$((i % 5 == 0))

    if [[ $div3 -eq 0 && $div5 -eq 0 ]]; then
        echo "$i"
        continue
    fi
    if [ $div3 -eq 1 ]; then
        echo -n "Fizz"
    fi
    if [ $div5 -eq 1 ]; then
        echo -n "Buzz"
    fi
    echo ""
    
    
done


