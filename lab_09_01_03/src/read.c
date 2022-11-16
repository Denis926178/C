#include "read.h"

int read_structure(product_t *product, FILE *f_src)
{
    size_t len = 0;
    char *name = NULL;
    int code_return;

    if ((code_return = getline(&name, &len, f_src)) == -1)
    {
        free(name);
        return code_return;
    }
    
    product->name = strdup(name);
    free(name); 
    int flag = EXIT_SUCCESS;

    if (fscanf(f_src, "%d\n", &product->cost) != READ_NUMBER)
        flag = ERROR_DATA_FILE;

    if (!flag && product->cost <= 0)
        flag = ERROR_COST;

    return flag;
}

int read_number_records(int *count_products, FILE *f_src)
{
    int flag = EXIT_SUCCESS;

    if (fscanf(f_src, "%d\n", count_products) != READ_NUMBER)
        flag = ERROR_DATA_FILE;

    if (!flag && (*count_products > MAX_PRODUCTS || *count_products < MIN_PRODUCTS))
        flag = ERROR_PRODUCT_COUNT;

    return flag;
}

int read_file(product_t *products, int count_products, FILE *f_src)
{ 
    int code_return, flag = EXIT_SUCCESS; 

    for (int i = 0; i < count_products; i++)
        if (!flag && (code_return = read_structure(products + i, f_src)))
            flag = code_return;

    return flag;
}
