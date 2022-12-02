#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE                    1
#define EXPECTED_NUMBER_ELEMENTS    1
#define MAX_SIZE                    10
#define ERROR_TYPE_ROW              2
#define ERROR_TYPE_COLUMN           3
#define ERROR_SIZE_ROW              4
#define ERROR_SIZE_COLUMN           5
#define ERROR_TYPE_MATRIX_ELEMENT   6
#define SWAP(a, b){     \
        int temp = a;   \
        a = b;          \
        b = temp;       \
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
            if (scanf("%d", *(matrix + i) + j) != EXPECTED_NUMBER_ELEMENTS)
                return ERROR_TYPE_MATRIX_ELEMENT;

    return EXIT_SUCCESS;
}

int find_min_row_matrix(int array[], size_t columns)
{
    int min = array[0];

    for (size_t i = 1; i < columns; i++)
        if (array[i] < min)
            min = array[i];

    return min;
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

void swap_two_row_matrix(int (*const matrix)[MAX_SIZE], size_t const columns, size_t const *j)
{
    for (size_t k = 0; k < columns; k++)
        SWAP(matrix[*j - 1][k], matrix[*j][k]);
}

void sort_matrix(int (*const matrix)[MAX_SIZE], size_t const rows, size_t const columns)
{
    for (size_t i = 0; i < rows - 1; i++)
        for (size_t j = rows - 1; j > i; j--)
            if (find_min_row_matrix(matrix[j - 1], columns) < find_min_row_matrix(matrix[j], columns))
                swap_two_row_matrix(matrix, columns, &j);
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
    
    sort_matrix(matrix, rows, columns);
    print_matrix(matrix, rows, columns);
        
    return EXIT_SUCCESS;
}
