#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#define LEN_NAME                25
#define ERROR_COST              4

typedef struct prduct
{
    char name[LEN_NAME + 1];
    int cost;
} product_t;

int isnumber(char string[], int len_string);
int isletters(char string[], int len_string);
int read_structure(product_t products[], int const index, FILE *const f_src);
int read_file(product_t products[], int *const count_products, FILE *const f_src);
void print_data(product_t const products[], int const count_products, int const cost);

#endif
