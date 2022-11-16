#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "main_functions.h"
#include "filter.h"
#include "sort_array.h"
#include "read_print_file.h"

int main(int argc, char *argv[])
{   
    FILE *f_in = NULL;
    FILE *f_out = NULL;
    int code_return;    
 
    if ((code_return = check_files_errors(argc, argv, &f_in, &f_out)))
        return code_return;

    int counter;
    int *array = NULL;
    
    if ((code_return = count_numbers(f_in, &counter)))
    { 
        close_files(f_in, f_out);
        return code_return;
    }

    if ((code_return = init_array(&array, f_in, counter)))
    {
        close_files(f_in, f_out);
        return code_return;
    }
    
    int mode = 0;
    select_mode(argc, argv, &mode);

    switch (mode)
    {
        case MODE_FILTER_SORT:
            code_return = execute_mode_filter_sort(f_out, &array, counter);
            break;
        case MODE_SORT:
            execute_mode_sort(f_out, &array, counter, compare_int);
            break;
        default:
            code_return = mode;
            break;
    }

    close_files(f_in, f_out);
    free(array);
    
    return code_return;
}
