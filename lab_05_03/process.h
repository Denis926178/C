#ifndef __PROCESS__H__
#define __PROCESS__H__

#include <stdlib.h>
#include <stdio.h>

int get_number_by_pos(FILE *const f, size_t pos, int *const number);
int put_number_by_pos(FILE *const f, size_t pos, int number);
int size_file(FILE *const f, size_t *const size);
int input_numbers(FILE *const f, char *count_numbers);
int print_numbers(FILE *const f);
int sort_bubble_numbers(FILE *const f);

#endif
