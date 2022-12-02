#ifndef SORT_H
#define SORT_H

#include <stddef.h>

#include "struct.h"

int comparator(int *left, int *right);
matrix_list_t *sort(matrix_list_t *head, int (*comparator)(int *, int *));
void sorted_insert(matrix_list_t **head, matrix_list_t *element, int (*comparator)(int *, int *));

#endif
