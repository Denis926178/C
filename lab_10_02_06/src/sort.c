#include "sort.h"
#include <stdio.h>

int comparator(int *left, int *right)
{
    return *left - *right;
}

matrix_list_t *sort(matrix_list_t *head, int (*comparator)(int *, int *))
{
    if (!head || !comparator)
        return NULL;
    
    matrix_list_t *new_head = NULL, *next_element;

    while (head != NULL)
    {
        next_element = head->next;
        sorted_insert(&new_head, head, comparator);
        head = next_element;
    }

    return new_head;
}

void sorted_insert(matrix_list_t **head, matrix_list_t *element, int (*comparator)(int *, int *))
{
    element->next = NULL;
    
    if (!(*head))
    {
        *head = element;
        return;
    }

    matrix_list_t *temp_head = *head;

    if (comparator(&temp_head->row, &element->row) == 0 && comparator(&temp_head->col, &element->col) > 0)
    {
        matrix_list_t *temp_element = *head;
        *head = element;
        element->next = temp_element;
        return;
    }
    else if (comparator(&temp_head->row, &element->row) > 0)
    {
        matrix_list_t *temp_element = *head;
        *head = element;
        element->next = temp_element;
        return;
    }

    while (temp_head->next != NULL)
    {
        if ((comparator(&temp_head->next->row, &element->row) == 0 && comparator(&temp_head->next->col, &element->col) > 0) || (comparator(&temp_head->next->row, &element->row) > 0))
        {
            matrix_list_t *temp_element = temp_head->next;
            temp_head->next = element;
            element->next = temp_element;
            return;
        }
        
        temp_head = temp_head->next;
    }

    temp_head->next = element;
}
