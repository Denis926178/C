#!/bin/bash

current_dir=$(dirname "$0")

i_pos=0
i_neg=0

arr_pos_in=()
arr_pos_out=()
arr_neg_in=()
arr_neg_args=()
arr_pos_args=()
mapfile -t arr_pos_in <<< "$(find "$current_dir/../data" -name "pos_[0-9][0-9]_in.txt" | sort)"
mapfile -t arr_pos_out <<< "$(find "$current_dir/../data" -name "pos_[0-9][0-9]_out.txt" | sort)"
mapfile -t arr_neg_in <<< "$(find "$current_dir/../data" -name "neg_[0-9][0-9]_in.txt" | sort)"
mapfile -t arr_neg_args <<< "$(find "$current_dir/../data" -name "neg_[0-9][0-9]_args.txt" | sort)"
mapfile -t arr_pos_args <<< "$(find "$current_dir/../data" -name "pos_[0-9][0-9]_args.txt" | sort)"

len_pos=${#arr_pos_in[@]}

for ((i=0; i<len_pos;i++))
do  
    if [ -n "$USE_VALGRIND" ]; then
        "$current_dir/./pos_case.sh" "${arr_pos_in[i]}" "${arr_pos_out[i]}" "${arr_pos_args[i]}"
        return_code=$?
        if [ $return_code -eq 0 ]; then
            echo "TEST: $((i+1)): PASSED MEMORY: PASSED"
            i_pos=$((i_pos+1))
        fi
        if [ $return_code -eq 1 ]; then
            echo "TEST: $((i+1)): FAILED MEMORY: PASSED"
        fi
        if [ $return_code -eq 2 ]; then
            echo "TEST: $((i+1)): PASSED MEMORY: FAILED"
            i_pos=$((i_pos+1))
        fi
        if [ $return_code -eq 3 ]; then
            echo "TEST: $((i+1)): FAILED MEMORY: FAILED"
        fi
    else
        "$current_dir/./pos_case.sh" "${arr_pos_in[i]}" "${arr_pos_out[i]}" "${arr_pos_args[i]}"
        return_code=$?
        if [ $return_code -eq 0 ]; then
            i_pos=$((i_pos+1))
            echo "TEST $((i+1)): PASSED"
        else
            echo "TEST $((i+1)): FAILED"
        fi
    fi
done

len_neg=${#arr_neg_in[@]}

for ((i=0; i<len_neg;i++))
do
    if [ -n "$USE_VALGRIND" ]; then
        "$current_dir/./neg_case.sh" "${arr_neg_in[i]}" "${arr_neg_args[i]}"
        return_code=$?
        if [ $return_code -eq 0 ]; then
            echo "TEST: $((i+1)): PASSED MEMORY: PASSED"
            i_neg=$((i_neg+1))
        fi
        if [ $return_code -eq 1 ]; then
            echo "TEST: $((i+1)): FAILED MEMORY: PASSED"
        fi
        if [ $return_code -eq 2 ]; then
            echo "TEST: $((i+1)): PASSED MEMORY FAILED"
            i_neg=$((i_neg+1))
        fi
        if [ $return_code -eq 3 ]; then
            echo "TEST: $((i+1)): PASSED MEMORY FAILED"
        fi

    else
        "$current_dir/./neg_case.sh" "${arr_neg_in[i]}" "${arr_neg_args[i]}"
        return_code=$?
        if [ $return_code -eq 0 ]; then
            i_neg=$((i_neg+1))
            echo "TEST $((i+1)): PASSED"
        else
            echo "TEST $((i+1)): FAILED"
        fi
    fi
done

echo "Positive tests: correct $i_pos of $len_pos"
echo "Negative tests: correct $i_neg of $len_neg"

number_fail=$((len_neg+len_pos-i_pos-i_neg))

exit $number_fail
