#ifndef INPUT_OUTPUT_H
#define INPUT_OUTPUT_H

#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "create_list.h"

#define READ_NUMBER         1
#define ERROR_READ_SIZE     2
#define ERROR_MEMORY        3
#define ERROR_READ_ELEMENT  4

void print_list(node_t *head);
int read_data(FILE *f_in, int **array, node_t **head, int *number);

#endif
