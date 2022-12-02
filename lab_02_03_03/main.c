// Вставить после каждого положительного элемента его реверс

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE            10
#define WRONG_TYPE_SIZE     20
#define WRONG_SIZE_ARRAY    30
#define WRONG_ARRAY_ELEMENT 40

void print_array(int *const array, size_t const size_array)
{
    for (size_t i = 0; i < size_array; i++)
        printf("%d ", array[i]);
}

int input_size_array(size_t *const size_array)
{
    int code_return = EXIT_SUCCESS;
    
    if (!scanf("%zu", size_array))
        code_return = WRONG_TYPE_SIZE;
    else if (*size_array > MAX_SIZE || *size_array < 1)
        code_return = WRONG_SIZE_ARRAY;

    return code_return;
}

int input_array(int *const array, size_t const size_array)
{
    int code_return = EXIT_SUCCESS;

    for (size_t i = 0; i < size_array; i++)
        if (scanf("%d", array + i) != 1)
            code_return = WRONG_ARRAY_ELEMENT;

    return code_return;
}

int number_reverse(int number)
{
    int result = 0;
    while (number)
    {
        result = result * 10 + number % 10;
        number /= 10;
    }

    return result;
}

void create_new_array(int *const array, size_t const size_array, int *const new_array, size_t *const counter)
{
    for (size_t i = 0; i < size_array; i++)
    {
        new_array[i + (*counter)] = array[i];
        if (array[i] > 0)
            new_array[i + ++(*counter)] = number_reverse(array[i]);
    }
}

int main(void)
{
    int array[MAX_SIZE];
    size_t size_array;
    int code_return = input_size_array(&size_array);

    if (code_return)
        return code_return;

    code_return = input_array(array, size_array);

    if (code_return)
        return code_return;
    
    int new_array[2 * MAX_SIZE];
    size_t counter = 0;
    create_new_array(array, size_array, new_array, &counter);
    print_array(new_array, size_array + counter);

    return EXIT_SUCCESS;
}
