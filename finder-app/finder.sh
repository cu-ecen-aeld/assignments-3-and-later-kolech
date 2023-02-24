#!/bin/bash

if [ "$#" -ne "2" ]; then
    echo "missing arguments"
    exit 1 
elif [ ! -d "$1" ]; then
    echo "$1 is not a directory"
    exit 1 
else
    filedir=$1
    searchstr=$2

    count=0
    sum=0

    for c in $(grep -rhc "${searchstr}" "${filedir}"); do
        if [ "$c" -ne "0" ]; then
            count=$((count + 1))
            sum=$((sum + $c))
        fi
    done

    echo "The number of files are ${count} and the number of matching lines are ${sum}"
fi
