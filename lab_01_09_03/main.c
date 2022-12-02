#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define INPUT_NUMBER 1

int main(void)
{
    double x;

    if (scanf("%lf", &x) != INPUT_NUMBER || x < 0)
        return EXIT_FAILURE;

    double search_function;
    int counter = 0;
    double multiplication = 1;

    while (x >= 0)
    {
        counter++;
        multiplication *= (x + counter);

        if (scanf("%lf", &x) != INPUT_NUMBER)
            return EXIT_FAILURE;
    }
    
    search_function = exp(1 / multiplication);
    printf("%lf", search_function);

    return EXIT_SUCCESS;
}
