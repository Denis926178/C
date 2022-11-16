#include <stdio.h>

#include "read_print_file.h"

int read_file(FILE *f_in)
{   
    int temp = 0;
    int counter = 0;

    while (fscanf(f_in, "%d", &temp) == SCANF_NUMBER)
        counter++;
    
    return counter;
}

void read_numbers(FILE *f_in, int *start, int *end)
{
    for (int *i = start; i < end; i++)
        fscanf(f_in, "%d", i);
}

void print_array(FILE *f, int *start, int *end)
{
    for (int *i = start; i < end; i++)
        fprintf(f, "%d ", *i);
    fprintf(f, "\n");
}
