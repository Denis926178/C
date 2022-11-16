#include <stdio.h>
#include <stdlib.h>

#include "functions.h"

#define ARGS_NUMBER             3
#define INDEX_COST              2
#define INDEX_FILE_SRC          1
#define MAX_LEN_ARRAY           15

#define ERROR_ARGS_NUMBER       1
#define ERROR_OPEN_FILE         2
#define ERROR_CLOSE_FILE        3

int main(int args, char *argv[])
{
    if (args != ARGS_NUMBER)
        return ERROR_ARGS_NUMBER;

    int count_products; 
    int const cost = atoi(argv[INDEX_COST]);

    if (cost <= 0)
        return ERROR_COST;

    product_t products[MAX_LEN_ARRAY];

    FILE *f_src = fopen(argv[INDEX_FILE_SRC], "r");

    if (f_src == NULL)
        return ERROR_OPEN_FILE;

    int code_return = read_file(products, &count_products, f_src);
    
    if (fclose(f_src) == EOF)
        return ERROR_CLOSE_FILE;

    if (code_return)
        return code_return;

    print_data(products, count_products, cost);
    
    return EXIT_SUCCESS;
}
