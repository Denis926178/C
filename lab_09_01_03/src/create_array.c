#include "create_array.h"

int comparator(void *a, void *b)
{
    int *left = a;
    int *right = b;
    
    return *left - *right;
}

int count_need_products(product_t *products, int size, int cost)
{
    int counter = 0;

    for (int i = 0; i < size; i++) 
        if (products[i].cost < cost)
            counter++;
        
    return counter;
}

void init_new_products(product_t *products, product_t *new_products, int size, int cost, int (*comparator)(void*, void*))
{
    int counter = 0;

    for (int i = 0; i < size; i++)
        if ((comparator(&products[i].cost, &cost)) < 0)
        {
            new_products[counter].cost = products[counter].cost;
            new_products[counter].name = products[counter].name;
            counter++;
        }
}
