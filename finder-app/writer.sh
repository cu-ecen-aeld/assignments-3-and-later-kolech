#!/bin/bash

if [ "$#" -ne "2" ]; then
    echo "missing arguments"
    exit 1 
else
    writefile=$1
    writestr=$2
    mkdir -p $(dirname ${writefile})
    echo "${writestr}" > ${writefile}
fi
