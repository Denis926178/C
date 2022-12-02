#include "process.h"

#define INPUT_NUMBER           1
#define ERROR_INPUT_ELEMENTS   -2

int find_count_numbers(FILE *const f, int *const counter_number)
{
    double mean_arithmetic;

    if (find_mean_arithmetic(f, &mean_arithmetic))
        return ERROR_INPUT_ELEMENTS;

    rewind(f);
    *counter_number = count_numbers(f, mean_arithmetic);

    return EXIT_SUCCESS;
}

int count_numbers(FILE *const f, const double mean_arithmetic)
{
    int counter = 0;
    int temp;

    while (fscanf(f, "%d", &temp) == INPUT_NUMBER)
        if (temp > mean_arithmetic)
            counter++;

    return counter;
}

int find_mean_arithmetic(FILE *const f, double *const mean_arithmetic)
{
    int temp;

    if (fscanf(f, "%d", &temp) != INPUT_NUMBER)
        return ERROR_INPUT_ELEMENTS;

    int max = temp, min = temp;

    while (fscanf(f, "%d", &temp) == INPUT_NUMBER)
    {
        if (temp > max)
            max = temp;

        if (temp < min)
            min = temp;
    }

    *mean_arithmetic = (max + min) * 0.5;
    return EXIT_SUCCESS;
}
