#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "sort.h"
#include "input_output.h"
#include "execute_modes.h"

#define INDEX_FILE          1
#define ARGS_NUMBER         2
#define ERROR_ARGS_NUMBER   1

int main(int argc, char **argv)
{
    if (argc != ARGS_NUMBER)
        return ERROR_ARGS_NUMBER;

    FILE *f_in = fopen(argv[INDEX_FILE], "r");
    node_t *head = NULL;
    int *array = NULL, number;

    int code_return = read_data(f_in, &array, &head, &number);

    if (!code_return)
    {
        head = sort(head, comparator);
        remove_duplicates(&head, comparator);
        print_list(head);
    }

    list_free(head);
    free(array);

    return EXIT_SUCCESS;
}