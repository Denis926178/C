#ifndef MATH_OPTIONS_H
#define MATH_OPTIONS_H

void summarize_matrix(double **matrix_1, double **matrix_2, double **res_matrix, int rows, int columns);
void multiply_matrix(double **matrix_1, double **matrix_2, double **res_matrix, int rows_1, int rows_2, int columns_2);
void get_matrix_without_row_and_col(double **matrix, int size, int row, int col, double **new_matrix);
double count_determinant(double **matrix, int size);
void determinant_big_size(double **matrix, int size, double *det, int *degree);

#endif
