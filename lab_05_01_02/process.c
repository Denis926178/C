#include "process.h"

#define ERROR_INPUT_ELEMENTS   -1
#define INPUT_NUMBER            1

int process(FILE *const f, int *const position)
{
    int max;

    if (fscanf(f, "%d", &max) != INPUT_NUMBER)
        return ERROR_INPUT_ELEMENTS;

    int temp_element;
    int position_max = 1;

    for (int counter = 2; fscanf(f, "%d", &temp_element) == INPUT_NUMBER; counter++)
        if (temp_element > max)
        {
            max = temp_element;
            position_max = counter;
        }

    *position = position_max;
    return EXIT_SUCCESS;
}       
