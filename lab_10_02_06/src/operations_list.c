#include "operations_list.h"

matrix_list_t *element_create(int row, int col, int value)
{
    matrix_list_t *temp = malloc(sizeof(matrix_list_t));

    if (!temp)
        return NULL;

    temp->col = col;
    temp->row = row;
    temp->value = value;
    temp->next = NULL;

    return temp;
}

matrix_list_t *list_add(matrix_list_t *head, matrix_list_t *temp)
{
    matrix_list_t *cur = head;

    if (!head)
        return temp;

    while (cur->next != NULL)
        cur = cur->next;

    cur->next = temp;

    return head;
}

void list_free(matrix_list_t *head)
{
    matrix_list_t *next;

    for (; head; head = next)
    {
        next = head->next;
        free(head);
    }
}

int find_string_max_element(matrix_list_t *matrix)
{
    matrix_list_t *temp = matrix;
    int index_string_max_el = 0;
    int max_element = matrix->value;

    while (temp != NULL)
    {
        if (temp->value > max_element)
        {
            max_element = temp->value;
            index_string_max_el = temp->row;
        }
        temp = temp->next;
    }

    return index_string_max_el;
}

matrix_list_t *pop(int index_string_max_el, matrix_list_t *matrix)
{
    matrix_list_t *prev = NULL;
    matrix_list_t *cur = matrix;

    for (cur = matrix; cur; cur = cur->next)
    {
        if (cur->row == index_string_max_el)
        {
            if (prev)
                prev->next = cur->next;
            else
                matrix = cur->next;
            free(cur);
            return matrix;
        }
        prev = cur;
    }

    return NULL;
}
