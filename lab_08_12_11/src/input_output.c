#include "input_output.h"

void print_matrix(FILE *f_output, double **matrix, int rows, int columns)
{
    fprintf(f_output, "%d %d\n", rows, columns);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
            fprintf(f_output, "%lf ", matrix[i][j]);
        fprintf(f_output, "\n");
    }

    rewind(f_output);
}

int read_matrix(FILE *f_in, int rows, int columns, double **matrix)
{
    int flag = EXIT_SUCCESS;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (!flag && fscanf(f_in, "%lf", &matrix[i][j]) != READ_NUMBER)
                flag = ERROR_READ_DATA;
    
    rewind(f_in);
    return flag;
}
