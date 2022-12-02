#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE                1
#define MAX_SIZE                10
#define ERROR_TYPE_ROW          2
#define ERROR_TYPE_COLUMN       3
#define ERROR_SIZE_ROW          4
#define ERROR_SIZE_COLUMN       5
#define ERROR_SQUARE_MATRIX     6

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

    if (*columns != *rows)
        return ERROR_SQUARE_MATRIX;

    return EXIT_SUCCESS;
}

void print_matrix(int (*const matrix)[MAX_SIZE], size_t const rows, size_t const columns)
{
    for (size_t i = 0; i < rows; i++)
    {
        for (size_t j = 0; j < columns; j++)
            printf("%d ", *(*(matrix + i) + j));
        printf("\n");
    }
}

void create_matrix(int (*const matrix)[MAX_SIZE], size_t const rows)
{
    size_t number_round = rows / 2;
    int counter = 1;

    for (size_t i = 0; i < number_round; i++)
    {
        for (size_t j = i; j < rows - i; j++)
            matrix[j][i] = counter++;
        for (size_t j = i + 1; j < rows - i; j++)
            matrix[rows - i - 1][j] = counter++;
        for (size_t j = i + 1; j < rows - i; j++)
            matrix[rows - j - 1][rows - i - 1] = counter++;
        for (size_t j = i + 1; j < rows - i - 1; j++)
            matrix[i][rows - j - 1] = counter++;
    }

    if (rows % 2)
        matrix[number_round][number_round] = counter;
}
int main(void)
{   
    size_t rows, columns;
    int matrix[MAX_SIZE][MAX_SIZE];
    int code_return = input_matrix_size(&rows, &columns);

    if (code_return)
        return code_return;

    create_matrix(matrix, rows);
    print_matrix(matrix, rows, columns);

    return EXIT_SUCCESS;
}
