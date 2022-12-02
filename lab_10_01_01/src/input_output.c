#include "input_output.h"

void print_list(node_t *head)
{
    node_t *cur = head;

    while (cur != NULL)
    {
        printf("%d ", *(int *)cur->data);
        cur = cur->next;
    }

    printf("\n");
}

int read_data(FILE *f_in, int **array, node_t **head, int *number)
{
    if (fscanf(f_in, "%d", number) != READ_NUMBER)
        return ERROR_READ_SIZE;
    
    *array = malloc(*number * sizeof(int));

    if (*array == NULL)
        return ERROR_MEMORY;
    
    for (int i = 0; i < *number; i++)
    {
        if (fscanf(f_in, "%d", (*array + i)) != READ_NUMBER)
            return ERROR_READ_ELEMENT;

        node_t *temp = node_create((*array + i));
        *head = list_add(*head, temp);
    }
    
    return EXIT_SUCCESS;
}
