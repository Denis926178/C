#include "print.h"

void print_data(product_t *products, int count_products)
{
    for (int i = 0; i < count_products; i++)
        printf("%s%d\n", products[i].name, products[i].cost);
}
