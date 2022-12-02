#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE                    1
#define MAX_SIZE                    10
#define EXPECTED_NUMBER_ELEMENTS    1
#define ERROR_TYPE_ROW              2
#define ERROR_TYPE_COLUMN           3
#define ERROR_SIZE_ROW              4
#define ERROR_SIZE_COLUMN           5
#define ERROR_TYPE_MATRIX_ELEMENT   6

void print_array(int const *const array, size_t const size_array)
{
    for (size_t i = 0; i < size_array; i++)
        printf("%d ", array[i]);
}

int input_matrix_size(size_t *const rows, size_t *const columns)
{  
    if (!scanf("%zu", rows))
        return ERROR_TYPE_ROW;

    if (*rows > MAX_SIZE || *rows < MIN_SIZE)
        return ERROR_SIZE_ROW;

    if (!scanf("%zu", columns))
        return ERROR_TYPE_COLUMN;

    if (*columns > MAX_SIZE || *columns < MIN_SIZE)
        return ERROR_SIZE_COLUMN;

    return EXIT_SUCCESS;
}

int input_matrix(int (*const matrix)[MAX_SIZE], size_t const rows, size_t const columns)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            if (scanf("%d", &matrix[i][j]) != EXPECTED_NUMBER_ELEMENTS)
                 return ERROR_TYPE_MATRIX_ELEMENT;

    return EXIT_SUCCESS;
}

void is_non_decreasing(int (*const matrix)[MAX_SIZE], size_t const rows, size_t const columns, int *const array)
{
    for (size_t i = 0; i < rows; i++)
    {
        int flag_pos = 1;

        if (columns == 1)
            flag_pos = 0;

        for (size_t j = 0; j < columns - 1; j++)
            if (matrix[i][j] > matrix[i][j + 1])
                flag_pos = 0;

        if (flag_pos)
            array[i] = 1;
    }
}

void is_non_growing(int (*const matrix)[MAX_SIZE], size_t const rows, size_t const columns, int *const array)
{
    for (size_t i = 0; i < rows; i++)
    {
        int flag_neg = 1;

        if (columns == 1)
            flag_neg = 0;

        for (size_t j = 0; j < columns - 1; j++)
            if (matrix[i][j] < matrix[i][j + 1])
                flag_neg = 0;
        
        if (flag_neg)
            array[i] = 1;
    }
}

int main(void)
{
    size_t rows, columns;
    int matrix[MAX_SIZE][MAX_SIZE];
    int code_return = input_matrix_size(&rows, &columns);

    if (code_return)
        return code_return;

    code_return = input_matrix(matrix, rows, columns);

    if (code_return)
        return code_return;

    int array[MAX_SIZE] = { 0 };
    
    is_non_growing(matrix, rows, columns, array);
    is_non_decreasing(matrix, rows, columns, array);    
    print_array(array, rows);
        
    return EXIT_SUCCESS;
}
