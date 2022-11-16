#include <stdio.h>
#include <stdlib.h>

#include "filter.h"

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst)
{
    int counter = 0;

    if (pb_src >= pe_src)
        return ERROR_KEY_DATA;
    
    for (const int *i = pb_src; i < pe_src && *i > 0; i++)
        counter++;

    if (counter == 0)
        return ERROR_ALL_NUMBERS_NEG;

    int *new_array = NULL;
    new_array = (int*)malloc(counter * sizeof(int));

    if (new_array == NULL)
    {   
        free(new_array);
        return ERROR_MEMORY;
    }
    
    for (int j = 0; j < counter; j++)
        *(new_array + j) = *(pb_src + j);
    
    *pb_dst = new_array;
    *pe_dst = new_array + counter;

    return EXIT_SUCCESS;
}
