#ifndef READ_PRINT_FILE_H
#define READ_PRINT_FILE_H

#define SCANF_NUMBER        1

int read_file(FILE *f_in);
void read_numbers(FILE *f_in, int *start, int *end);
void print_array(FILE *f, int *start, int *end);

#endif
