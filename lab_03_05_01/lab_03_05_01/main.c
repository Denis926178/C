#include <stdio.h>
#include <stdlib.h>

#define MIN_SIZE                    1
#define MAX_SIZE                    10
#define ERROR_TYPE_ROW              2
#define ERROR_TYPE_COLUMN           3
#define ERROR_SIZE_ROW              4
#define ERROR_SIZE_COLUMN           5
#define ERROR_TYPE_MATRIX_ELEMENT   6
#define AMOUNT_CONDITION            10
#define SYS_NUM                     10

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

int sum_figures_number(int number)
{
    int sum = 0;

    while (number)
    {
        sum += number % SYS_NUM;
        number /= SYS_NUM;
    }

    return sum;
}

void shift_array(int array[], int rows)
{
    int start = array[0];

    for (int i = 0; i < rows - 1; i++)
        array[i] = array[i + 1];

    array[rows - 1] = start;
}

size_t create_array(int (*const matrix)[MAX_SIZE], size_t const rows, size_t const columns, int *const array, size_t *const counter)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            if (sum_figures_number(abs(matrix[i][j])) > AMOUNT_CONDITION)
                array[(*counter)++] = matrix[i][j];

    if ((*counter) == 0)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

void update_matrix(int (*const matrix)[MAX_SIZE], size_t const rows, size_t const columns, int *const array)
{
    size_t counter = 0;

    for (size_t i = 0; i < rows; i++)
        for (size_t j = 0; j < columns; j++)
            if (sum_figures_number(abs(matrix[i][j])) > AMOUNT_CONDITION)
                matrix[i][j] = array[counter++];
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
    
    int array[MAX_SIZE * MAX_SIZE];
    size_t counter = 0;
    code_return = create_array(matrix, rows, columns, array, &counter);

    if (code_return)
        return code_return;

    for (int i = 0; i < 3; i++)
        shift_array(array, counter);
    
    update_matrix(matrix, rows, columns, array);
    print_matrix(matrix, rows, columns);

    return EXIT_SUCCESS;
}
