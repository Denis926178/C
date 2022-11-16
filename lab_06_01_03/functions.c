#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "functions.h"

#define READ_NUMBER             1
#define MIN_PRODUCTS            1
#define MAX_PRODUCTS            15
#define READ_NUMBER             1

#define ERROR_EMPTY_STRING      5
#define ERROR_PRODUCT_COUNT     6
#define ERROR_DATA_FILE         7
#define ERROR_SIZE_FILE         8

int isnumber(char string[], int len_string)
{
    for (int i = 0; i < len_string - 1; i++)
        if (!isdigit(string[i]))
            return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int isletters(char string[], int len_string)
{
    for (int i = 0; i < len_string - 1; i++)
        if (!isspace(string[i]))
            return EXIT_SUCCESS;

    return EXIT_FAILURE;
}

int read_structure(product_t products[], int const index, FILE *const f_src)
{
    if (fgets(products[index].name, LEN_NAME + 2, f_src) == NULL)
        return ERROR_DATA_FILE;

    if (isletters(products[index].name, strlen(products[index].name)))
        return ERROR_EMPTY_STRING;

    if (fscanf(f_src, "%d\n", &products[index].cost) != READ_NUMBER)
        return ERROR_DATA_FILE;

    if (products[index].cost <= 0)
        return ERROR_COST;

    return EXIT_SUCCESS;
}

int read_file(product_t products[], int *const count_products, FILE *const f_src)
{ 
    int count_product_local;
    int code_return;
    char ch[LEN_NAME + 2];

    if (fgets(ch, LEN_NAME + 2, f_src) == NULL)
        return ERROR_DATA_FILE;

    if (isnumber(ch, strlen(ch)))
        return ERROR_DATA_FILE;

    count_product_local = atoi(ch);

    if (count_product_local > MAX_PRODUCTS || count_product_local < MIN_PRODUCTS)
        return ERROR_PRODUCT_COUNT;

    for (int i = 0; i < count_product_local; i++)
        if ((code_return = read_structure(products, i, f_src)))
            return code_return;

    if (fgets(ch, LEN_NAME + 2, f_src) != NULL)
        return ERROR_SIZE_FILE;
        
    *count_products = count_product_local;
    return EXIT_SUCCESS;
}

void print_data(product_t const products[], int const count_products, int const cost)
{
    for (int i = 0; i < count_products; i++)
        if (cost > products[i].cost)
            printf("%s%d\n", products[i].name, products[i].cost);
}
