#include <stdio.h> 
#include <stdlib.h>

#define MIN_SIZE                    1
#define MAX_SIZE                    10
#define ERROR_TYPE_ROW              2
#define ERROR_TYPE_COLUMN           3
#define ERROR_SIZE_ROW              4
#define ERROR_SIZE_COLUMN           5
#define ERROR_TYPE_MATRIX_ELEMENT   6
#define ERROR_SQUARE_MATRIX         7

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
    
    if (*rows != *columns)
        return ERROR_SQUARE_MATRIX;

    return EXIT_SUCCESS;
}

int input_matrix(int (*const matrix)[MAX_SIZE], size_t const rows, size_t const columns)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            if (!scanf("%d", *(matrix + i) + j))
                return ERROR_TYPE_MATRIX_ELEMENT;

    return EXIT_SUCCESS;
}

void print_matrix(int (*const matrix)[MAX_SIZE], size_t const rows, size_t const columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
            printf("%d ", matrix[i][j]);
        printf("\n");
    }
}

void swap_two_element(int *const first_element, int *const second_element)
{
    int temp = *first_element;
    *first_element = *second_element;
    *second_element = temp;
}

void swap_upper_half_matrix(int (*const matrix)[MAX_SIZE], size_t const rows, size_t const columns)
{
    for (size_t i = 0; i <= rows / 2; i++)
        for (size_t j = 0; j < i + 1; j++)
        {
            swap_two_element(&matrix[i][j], &matrix[i][columns - j - 1]);
            if (rows % 2 == 0 && rows / 2 == i && j == i)
                swap_two_element(&matrix[i][j], &matrix[i][columns - j - 1]);
        }
}

void swap_lower_half_matrix(int (*const matrix)[MAX_SIZE], size_t const rows, size_t const columns)
{
    for (size_t i = rows / 2 + 1; i < rows; i++)
        for (size_t j = 0; j < columns - i; j++)
            swap_two_element(&matrix[i][j], &matrix[i][columns - j - 1]);
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

    swap_upper_half_matrix(matrix, rows, columns);
    swap_lower_half_matrix(matrix, rows, columns);
    print_matrix(matrix, rows, columns);

    return EXIT_SUCCESS;
}
