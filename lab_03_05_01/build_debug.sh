#!/bin/bash

gcc -std=c99 -Wall -Werror -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -g3 -lm -Wvla -c main.c
gcc main.o -o app.exe -lm
