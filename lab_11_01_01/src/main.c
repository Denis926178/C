#include <stdio.h>
#include <stdlib.h>
#include "my_snprintf.h"

int main(void)
{  
    char buffer[50];
    char buffer_2[50];

    int j = my_snprintf(buffer, 50, "%d", 505);
    int k = snprintf(buffer_2, 50, "%d", 505);

    printf("%d %s %d %s\n", j, buffer, k, buffer_2);
    
    return EXIT_SUCCESS;
}