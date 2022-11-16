#include "memory_options.h"

void free_matrix(double **data, int n)
{
    for (int i = 0; i < n; i++)
        free(data[i]);

    free(data);
}

double **allocate_matrix(int n, int m)
{
    double **matrix = malloc(n * sizeof(double*));

    if (matrix == NULL)
        return NULL;

    for (int i = 0; i < n; i++)
    {
        matrix[i] = malloc(m * sizeof(double));

        if (matrix[i] == NULL)
        {
            free_matrix(matrix, n);
            return NULL;
        }
    }

    return matrix;
}
