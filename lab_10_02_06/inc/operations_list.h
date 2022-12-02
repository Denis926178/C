#ifndef OPERATIONS_LIST_H
#define OPERATIONS_LIST_H

#include <stdlib.h>

#include "struct.h"

matrix_list_t *element_create(int row, int col, int value);
matrix_list_t *list_add(matrix_list_t *head, matrix_list_t *temp);
void list_free(matrix_list_t *head);
int find_string_max_element(matrix_list_t *matrix);
matrix_list_t *pop(int index_string_max_el, matrix_list_t *matrix);

#endif
