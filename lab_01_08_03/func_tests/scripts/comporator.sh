#!/bin/bash

file1=$1
file2=$2 

if [ -f "$file1" ] && [ -f "$file2" ]; then
    IFS=" " read -r -a arr1 <<< "$(grep -Eo "Result: [0-9]+" "$file1")"
    IFS=" " read -r -a arr2 <<< "$(grep -Eo "Result: [0-9]+" "$file2")"
    string1="${arr1[0]}"
    string2="${arr2[0]}"
    if [[ "$string1" == "$string2" ]]; then
        exit 0
    else
        exit 1
    fi
else 
    exit 1
fi
