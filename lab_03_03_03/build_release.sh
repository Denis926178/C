#!/bin/bash

gcc -std=c99 -Wall -Wpedantic -Wextra -Wfloat-conversion -Wfloat-equal -lm -Wvla -c main.c
gcc main.o -o app.exe -lm
