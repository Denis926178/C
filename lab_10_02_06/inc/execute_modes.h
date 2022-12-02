#ifndef EXECUTE_MODES_H
#define EXECUTE_MODES_H

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "operations_list.h"
#include "input_output.h"
#include "sort.h"
#include "matrix_actions.h"

matrix_list_t *multiply(matrix_list_t *matrix_1, matrix_list_t *matrix_2);
int execute_multiply();
int execute_summarize();
int execute_print();
int execute_delete_element();

#endif
