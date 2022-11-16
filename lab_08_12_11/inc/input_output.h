#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>
#include <stdlib.h>

#define READ_NUMBER             1

#define ERROR_READ_DATA         8

void print_matrix(FILE *f_output, double **matrix, int rows, int columns);
int read_matrix(FILE *f_in, int rows, int columns, double **matrix);

#endif
