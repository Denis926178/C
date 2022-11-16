#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main_functions.h"
#include "filter.h"
#include "sort_array.h"
#include "read_print_file.h"

void close_files(FILE *f_in, FILE *f_out)
{
    fclose(f_in);
    fclose(f_out);
}

void select_mode(int argc, char **argv, int *mode)
{
    if (argc == 4 && strcmp(*(argv + INDEX_OPTION), "f") != 0)
        *mode = ERROR_ARGS_OPTION;
    else if (argc == 4)
        *mode = MODE_FILTER_SORT;
    else
        *mode = MODE_SORT;
}

int execute_mode_filter_sort(FILE *f_out, int **array, int counter)
{
    int *new_array_start = NULL;
    int *new_array_end = NULL;
    int code_return = key(*array, *array + counter, &new_array_start, &new_array_end);

    if (code_return)
    {
        free(new_array_start);
        return code_return;
    }

    mysort(new_array_start, new_array_end - new_array_start, sizeof(*new_array_start), compare_int);
    print_array(f_out, new_array_start, new_array_end);
    free(new_array_start);

    return EXIT_SUCCESS;
}

void execute_mode_sort(FILE *f_out, int **array, int counter, int (*compar)(const void*, const void*))
{
    mysort(*array, counter, sizeof(*array[0]), compar);
    print_array(f_out, *array, *array + counter);
}

int check_files_errors(int argc, char **argv, FILE **f_in, FILE **f_out)
{
    if (argc != 3 && argc != 4)
        return ERROR_ARGS_NUMBER;
    
    *f_in = fopen(*(argv + INDEX_IN_FILE), "r");
    
    if (*f_in == NULL)
        return ERROR_OPEN_FILE;

    *f_out = fopen(*(argv + INDEX_OUT_FILE), "w");

    if (*f_out == NULL)
    {
        if (fclose(*f_in) == EOF)
            return ERROR_CLOSE_FILE;
        else
            return ERROR_OPEN_FILE;
    }

    return EXIT_SUCCESS;
}

int count_numbers(FILE *f_in, int *counter)
{
    *counter = read_file(f_in);

    if (*counter == 0)
        return ERROR_NO_DATA_IN_FILE;

    return EXIT_SUCCESS;
}

int init_array(int **array, FILE *f_in, int counter)
{   
    *array = (int*)malloc(counter * sizeof(int));

    if (array == NULL)
        return ERROR_MEMORY;

    rewind(f_in);
    read_numbers(f_in, *array, *array + counter);

    return EXIT_SUCCESS;
}
