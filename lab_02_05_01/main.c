// Вычислить X[0] * Y[0] .. X[k-1] * Y[k-1],
// X - отрицательные элементы массив в порядке следования,
// Y - положительные элементы массива в обратном порядке следования,
// k - минимум из количества отрицательных и положительных элементов

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE            10
#define WRONG_TYPE_SIZE     20
#define WRONG_SIZE_ARRAY    30
#define WRONG_ARRAY_ELEMENT 40
#define NO_NEED_ELEMENTS    50

int input_size_array(size_t *const size_array)
{
    int code_return = EXIT_SUCCESS;

    if (scanf("%zu", size_array) != 1)
        code_return = WRONG_TYPE_SIZE;
    else if (*size_array > MAX_SIZE || *size_array < 1)
        code_return = WRONG_SIZE_ARRAY;

    return code_return;
}

int input_array(int *const start, int *const finish)
{
    int code_return = EXIT_SUCCESS;

    for (int *i = start; i < finish; i++)
        if (scanf("%d", i) != 1)
            code_return = WRONG_ARRAY_ELEMENT;
    
    return code_return;
}

int count_search_expression(int *const start, int *const finish, int *const sum)
{
    int *neg = start, *pos = finish;
    int code_return = EXIT_SUCCESS;

    while (neg <= finish && pos >= start)
        if (*pos > 0 && *neg < 0)
            *sum += *pos-- * *neg++;
        else if (*pos <= 0)
            pos--;
        else if (*neg >= 0)
            neg++;
    
    if (*sum == 0)
        code_return = NO_NEED_ELEMENTS;
    
    return code_return;
}

int main(void)
{
    int array[MAX_SIZE];
    size_t size_array;
    int code_return = input_size_array(&size_array);

    if (code_return)
        return code_return;

    int *start = array;
    int *finish = start + size_array;
    code_return = input_array(start, finish);

    if (code_return)
        return code_return;
    
    int sum = 0;
    finish--;
    code_return = count_search_expression(start, finish, &sum);

    if (code_return == NO_NEED_ELEMENTS)
        return NO_NEED_ELEMENTS;
    
    printf("%d\n", sum);

    return EXIT_SUCCESS;
}    
