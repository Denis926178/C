#!/bin/bash

gcc -std=c99 -Wall -Werror -Wvla -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -lm -g3 -c main.c
gcc main.o -o app.exe -lm
