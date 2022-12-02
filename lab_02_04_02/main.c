// Сортировка массива выбором

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE            11
#define ARRAY_OVERFLOW      100
#define NO_ARRAY_ELEMENT    20
#define MIN_SIZE            0

void print_array(int *const array, size_t const size_array)
{
    for (size_t i = 0; i < size_array; i++)
        printf("%d ", array[i]);
}

void selection_sort_array(int *const array, size_t const size_array)
{
    for (size_t i = 0; i < size_array; i++)
    {
        int index_max_element = i;

        for (size_t j = i + 1; j < size_array; j++)
            if (array[index_max_element] > array[j])
                index_max_element = j;

        int temp = array[index_max_element];
        array[index_max_element] = array[i];
        array[i] = temp;
    }

    print_array(array, size_array);
}

int input_array(int *const array)
{
    int return_code = EXIT_SUCCESS;
    size_t size_array = 0;

    while (scanf("%d", array + size_array) && size_array < MAX_SIZE)
        size_array++;

    return_code = size_array;

    if (size_array == MAX_SIZE)
        return_code = ARRAY_OVERFLOW;
    else if (size_array == MIN_SIZE)
        return_code = NO_ARRAY_ELEMENT;
    
    return return_code;   
}

int main(void)
{
    int array[MAX_SIZE];
    size_t size_array;
    int return_code = input_array(array);

    if (return_code == ARRAY_OVERFLOW)
        size_array = MAX_SIZE - 1;

    if (return_code == NO_ARRAY_ELEMENT)
        return return_code;
    
    if (return_code > MIN_SIZE && return_code < MAX_SIZE)
        size_array = return_code;
    
    selection_sort_array(array, size_array);

    if (return_code == ARRAY_OVERFLOW)
        return return_code;

    return EXIT_SUCCESS;
}
