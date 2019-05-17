#!/bin/bash

n=2
while [ $n -lt 10000 ]
do
    str="0"
    num=$n
    v=$(printf "%-${num}s" "$str")
    str=$(echo -n "${v// /*}")
    echo $n
#    echo $str
    diff <(echo -n $str | whirlpooldeep | sed -E 's/([0-9A-Za-z]+).*/\1/g') <(echo -n $str | ./ft_ssl whirlpool -q)
    n=$(($n+1))
done
