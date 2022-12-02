#!/bin/bash

gcc main.c --coverage -o app.exe
./func_tests/scripts/func_tests.sh
gcov main.c
