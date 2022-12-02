// Составить массив из чисел армстронга и вывести его

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EPS                     1e-6
#define NUM_SYS                 10
#define MAX_SIZE                10
#define WRONG_SIZE_ARRAY        20
#define WRONG_ARRAY_ELEMENT     30
#define WRONG_TYPE_SIZE         40
#define WRONG_NUMBER_ARMSTRONG  50

void print_array(int *array, size_t const size_array)
{
    for (size_t i = 0; i < size_array; i++)
        printf("%d ", array[i]);
}

size_t input_size_array(size_t *const size_array)
{
    size_t code_return = EXIT_SUCCESS;

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

int check_armstrong(int number)
{   
    int code_return = EXIT_SUCCESS;
    int len_number = 0;
    int clone_number = number;

    while (number)
    {   
        number /= NUM_SYS;
        len_number++;
    }

    double sum = 0; 
    number = clone_number;

    for (int i = 0; i < len_number; i++)
    {   
        sum += pow((clone_number % NUM_SYS), len_number);
        clone_number /= NUM_SYS;
    }

    if ((fabs(sum - number) < EPS) && (sum > EPS))
        code_return = EXIT_FAILURE;

    return code_return;
}

int create_new_array(int *const array, size_t const size_array, int *new_array, size_t *counter)
{
    int return_code = EXIT_SUCCESS;

    for (size_t i = 0; i < size_array; i++)
        if (check_armstrong(array[i]))
            new_array[(*counter)++] = array[i];
    
    if (!(*counter))
        return_code = WRONG_NUMBER_ARMSTRONG;

    return return_code;
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

    int new_array[MAX_SIZE];
    size_t counter = 0;
    code_return = create_new_array(array, size_array, new_array, &counter);
    
    if (code_return)
        return code_return;

    print_array(new_array, counter);

    return EXIT_SUCCESS;
}
