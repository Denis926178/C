#ifndef __PROCESS__H__
#define __PROCESS__H__

#include <stdio.h>
#include <stdlib.h>

int find_count_numbers(FILE *const f, int *const counter_number);
int count_numbers(FILE *const f, const double mean_arithmetic);
int find_mean_arithmetic(FILE *const f, double *const mean_arithmetic);

#endif
