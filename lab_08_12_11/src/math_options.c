#include "math_options.h"
#include "memory_options.h"

void summarize_matrix(double **matrix_1, double **matrix_2, double **res_matrix, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            res_matrix[i][j] = matrix_1[i][j] + matrix_2[i][j];
}

void multiply_matrix(double **matrix_1, double **matrix_2, double **res_matrix, int rows_1, int rows_2, int columns_2)
{
    for (int i = 0; i < rows_1; i++)
        for (int j = 0; j < columns_2; j++)
        {
            res_matrix[i][j] = 0;
            for (int k = 0; k < rows_2; k++)
                res_matrix[i][j] += matrix_1[i][k] * matrix_2[k][j];
        }
}

void get_matrix_without_row_and_col(double **matrix, int size, int row, int col, double **new_matrix)
{
    int offset_row = 0; 
    int offset_col = 0;

    for (int i = 0; i < size - 1; i++)
    {
        if (i == row)
            offset_row = 1;

        offset_col = 0; 

        for (int j = 0; j < size - 1; j++)
        {
            if (j == col)
                offset_col = 1;

            new_matrix[i][j] = matrix[i + offset_row][j + offset_col];
        }
    }
}

double count_determinant(double **matrix, int size)
{   
    double det = 0;
    int degree = 1;

    if (size == 1)
        return matrix[0][0];
    else if (size == 2)
        return matrix[0][0] * matrix[1][1] - matrix[0][1] * matrix[1][0];
    else
        determinant_big_size(matrix, size, &det, &degree);

    return det;
}

void determinant_big_size(double **matrix, int size, double *det, int *degree)
{
    double **new_matrix = allocate_matrix(size - 1, size - 1);

    for (int j = 0; j < size; j++)
    {
        get_matrix_without_row_and_col(matrix, size, 0, j, new_matrix);
        *det += (*degree * matrix[0][j] * count_determinant(new_matrix, size - 1));
        *degree = -*degree;
    }

    free_matrix(new_matrix, size - 1);
}
