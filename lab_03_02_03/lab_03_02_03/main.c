#include <stdio.h>
#include <stdlib.h>

#define MIN_FIGURE                  0
#define MAX_FIGURE                  9
#define MIN_SIZE                    1
#define MAX_SIZE                    10
#define EXPECTED_NUMBER_ELEMENTS    1
#define ERROR_TYPE_ROW              2
#define ERROR_TYPE_COLUMN           3
#define ERROR_SIZE_ROW              4
#define ERROR_SIZE_COLUMN           5 
#define ERROR_TYPE_MATRIX_ELEMENT   6
#define ERROR_TYPE_FIGURE           7
#define ERROR_SIZE_FIGURE           8
#define NUM_SYS                     10

int input_matrix_size(size_t *const rows, size_t *const columns)
{
    if (scanf("%zu", rows) != EXPECTED_NUMBER_ELEMENTS)
        return ERROR_TYPE_ROW;

    if (*rows > MAX_SIZE || *rows < MIN_SIZE)
        return ERROR_SIZE_ROW;

    if (scanf("%zu", columns) != EXPECTED_NUMBER_ELEMENTS)
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

int input_digit(int *const digit)
{
    if (scanf("%d", digit) != EXPECTED_NUMBER_ELEMENTS)
        return ERROR_SIZE_FIGURE;

    if (*digit > MAX_FIGURE || *digit < MIN_FIGURE)
        return ERROR_SIZE_FIGURE;

    return EXIT_SUCCESS;
}

int is_digit_in_number(int number, int digit)
{
    int temp_digit;
    
    if (number == digit)
        return EXIT_SUCCESS;

    while (number)
    {
        temp_digit = number % NUM_SYS;
        number /= NUM_SYS;

        if (temp_digit == digit)
            return EXIT_SUCCESS;
    }

    return EXIT_FAILURE;
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

void shift_matrix(int (*const matrix)[MAX_SIZE], size_t const rows, size_t *columns, size_t *stop_j, int *flag)
{
    for (size_t i = 0; i < rows; i++)
        for (size_t j = *stop_j; j < *columns - 1; j++)
            matrix[i][j] = matrix[i][j + 1];

    (*columns)--;
    *flag = 0;
    (*stop_j)--;
}

int create_new_matrix(int (*const matrix)[MAX_SIZE], size_t const rows, size_t *columns, int const digit)
{
    for (size_t j = 0; j < *columns; j++)
    {
        int flag = 1;
        
        for (size_t i = 0; i < rows; i++)
            if (flag == 1 && !is_digit_in_number(abs(matrix[i][j]), digit))
                shift_matrix(matrix, rows, columns, &j, &flag);
    }
    
    if (*columns == 0)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
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
    
    int digit;
    code_return = input_digit(&digit);

    if (code_return)
        return code_return;
    
    code_return = create_new_matrix(matrix, rows, &columns, digit);

    if (code_return)
        return code_return;

    print_matrix(matrix, rows, columns);

    return EXIT_SUCCESS;
}
