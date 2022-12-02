#include "sort.h"

int comparator(const void *left, const void *right)
{
    return *(int *)left - *(int *)right;
}

node_t *sort(node_t *head, int (*comparator)(const void *, const void *))
{
    if (!head || !comparator)
        return NULL;

    node_t *new_head = NULL, *next_element;

    while (head != NULL)
    {
        next_element = head->next;
        sorted_insert(&new_head, head, comparator);
        head = next_element;
    }

    return new_head;
}

void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *))
{
    element->next = NULL;

    if (!(*head))
    {
        *head = element;
        return;
    }

    node_t *temp_head = *head;

    if (comparator(temp_head->data, element->data) > 0)
    {
        node_t *temp_element = *head;
        *head = element;
        element->next = temp_element;
        return;
    }

    while (temp_head->next != NULL)
    {
        if (comparator(temp_head->next->data, element->data) > 0)
        {
            node_t *temp_element = temp_head->next;
            temp_head->next = element;
            element->next = temp_element;
            return;
        }

        temp_head = temp_head->next;
    }

    temp_head->next = element;
}