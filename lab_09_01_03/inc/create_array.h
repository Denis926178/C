#ifndef CREATE_ARRAY_H
#define CREATE_ARRAY_H

#include "struct.h"

int comparator(void *a, void *b);
int count_need_products(product_t *products, int size, int cost);
void init_new_products(product_t *products, product_t *new_products, int size, int cost, int (*comparator)(void*, void*));

#endif
