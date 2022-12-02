#include "input_output.h"

void print_list(matrix_list_t *head)
{
    matrix_list_t *cur = head;

    while (cur != NULL)
    {
        printf("%d %d %d ", cur->row, cur->col, cur->value);
        cur = cur->next;
    }

    printf("\n");
}

int read_matrix(matrix_list_t **matrix)
{
    int rows, columns;

    if (scanf("%d%d", &rows, &columns) != READ_SIZES)
        return ERROR_READ_SIZES;

    int temp;

    for (int i = 0; i < rows; i++)
        for (int j = 0; j < columns; j++)
            if (scanf("%d", &temp) != 1)
            {
                return ERROR_READ_MATRIX_ELEMENT;
            }
            else if (temp != 0)
            {
                matrix_list_t *temp_el = element_create(i, j, temp);
                *matrix = list_add(*matrix, temp_el);
            }

    return EXIT_SUCCESS;
}
