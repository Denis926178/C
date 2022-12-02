#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "operations_list.h"

#define READ_SIZES                  2
#define ERROR_READ_SIZES            2
#define ERROR_READ_MATRIX_ELEMENT   3

void print_list(matrix_list_t *head);
int read_matrix(matrix_list_t **matrix);

#endif
