#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <stdint.h>

#include "sort_array.h"

int compare_int(const void *left, const void *right)
{
    const int *a = left;
    const int *b = right;
    return *a - *b; 
}

void swap(void *a, void *b, size_t size)
{
    char *buffer = NULL;
    buffer = malloc(size);
    memcpy(buffer, a, size);
    memcpy(a, b, size);
    memcpy(b, buffer, size);
    free(buffer);
}

void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void*, const void*))
{
    for (size_t i = 0; i < nmemb; i++)
    {
        int flag = 1;
        for (size_t j = 0; j < nmemb - 1; j++)
            if (compar((uint8_t*)base + j * size, (uint8_t*)base + j * size + size) > 0)
            {
                flag = 0;
                swap((uint8_t*)base + j * size, (uint8_t*)base + j * size + size, size);
            }
        if (flag)
            break;
    }
}
