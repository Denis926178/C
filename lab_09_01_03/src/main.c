#include <stdio.h>
#include <stdlib.h>

#include "struct.h"
#include "read.h"
#include "print.h"
#include "free.h"
#include "create_array.h"

#define ARGS_NUMBER             3
#define INDEX_COST              2
#define INDEX_FILE_SRC          1
#define MAX_LEN_ARRAY           15

#define ERROR_ARGS_NUMBER       1
#define ERROR_OPEN_FILE         2
#define ERROR_CLOSE_FILE        3
#define ERROR_MEMORY            4
#define ERROR_READ_NUMBER       8
#define ERROR_READ              9

int main(int args, char **argv)
{
    if (args != ARGS_NUMBER)
        return ERROR_ARGS_NUMBER;

    int count_products; 
    int const cost = atoi(argv[INDEX_COST]);

    if (cost <= 0)
        return ERROR_COST;

    FILE *f_src = fopen(argv[INDEX_FILE_SRC], "r");

    if (f_src == NULL)
        return ERROR_OPEN_FILE;

    int code_return;
    
    if ((code_return = read_number_records(&count_products, f_src)))
    {  
        fclose(f_src);
        return ERROR_READ_NUMBER;
    }
    
    product_t *products = calloc(count_products, sizeof(product_t));

    if (products == NULL)
    {
        fclose(f_src);
        return ERROR_MEMORY;    
    }

    if ((code_return = read_file(products, count_products, f_src)))
    {
        fclose(f_src);
        free_struct(products, count_products);
        return ERROR_READ;
    }

    int count_new_products = count_need_products(products, count_products, cost);
    product_t *new_products = calloc(count_new_products, sizeof(product_t));

    if (new_products == NULL)
    {
        free_struct(products, count_products);
        fclose(f_src);
        return ERROR_MEMORY;
    }

    init_new_products(products, new_products, count_products, cost, comparator);
    print_data(new_products, count_new_products);
    
    free_struct(products, count_products);
    free(new_products);
    fclose(f_src);

    return EXIT_SUCCESS;
}
