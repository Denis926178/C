#ifndef STRUCT_H
#define STRUCT_H

typedef struct matrix_list_t
{
    int row;
    int col;
    int value;
    
    struct matrix_list_t *next;
} matrix_list_t;

#endif
