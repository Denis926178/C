#ifndef CHECK_ERRORS_H
#define CHECK_ERRORS_H

#include <stdio.h>
#include <stdlib.h>

#define INDEX_FIRST_FILE_IN         2
#define INDEX_SECOND_FILE_IN        3
#define INDEX_SECOND_FILE_OUT       3
#define INDEX_THIRD_FILE_OUT        4

#define ERROR_ARGS_NUMBER           1
#define ERROR_OPEN_FILE             2

int check_files_errors(int argc, char **argv);
int check_matrix(FILE *f_in);
int read_matrix_to_check(FILE *f_in, int rows, int columns);
int check_matrices(FILE *f_in_1, FILE *f_in_2, int flag);

#endif
