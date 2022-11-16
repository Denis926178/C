#ifndef EXECUTE_MODES_H
#define EXECUTE_MODES_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SUMMARIZE               1
#define MULTIPLY                2
#define DETERMINANT             3

#define INDEX_FIRST_FILE_IN     2
#define INDEX_SECOND_FILE_OUT   3
#define INDEX_SECOND_FILE_IN    3
#define INDEX_THIRD_FILE_OUT    4

#define READ_SIZES              2

#define ERROR_READ_SIZES        3
#define ERROR_MODE              4
#define ERROR_STRUCT_SIZES      5
#define ERROR_ALLOCATE_MEMORY   6
#define ERROR_READ_MATRIX       7

void select_mode(int argc, char **argv, int *mode);
int execute_summarize(char **argv);
int execute_mupltiply(char **argv);
int execute_determinant(char **argv);

#endif
