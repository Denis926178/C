#include "free.h"

void free_struct(product_t *products, int counter)
{
    for (int i = 0; i < counter; i++)
        free((products + i)->name);
    
    free(products);
}
