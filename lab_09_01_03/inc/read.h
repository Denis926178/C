#ifndef READ_H
#define READ_H

#define _POSIX_C_SOURCE 200809L

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "struct.h"

#define READ_NUMBER             1
#define MIN_PRODUCTS            1
#define MAX_PRODUCTS            15
#define READ_NUMBER             1

#define ERROR_COST              4
#define ERROR_PRODUCT_COUNT     6
#define ERROR_DATA_FILE         10

int read_structure(product_t *product, FILE *f_src);
int read_number_records(int *count_products, FILE *f_src);
int read_file(product_t *products, int count_products, FILE *f_src);

#endif
