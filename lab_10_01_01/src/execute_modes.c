#include "execute_modes.h"

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *))
{
    for (; head; head = head->next)
        if (!comparator(head->data, data))
            return head;

    return NULL;
}

void *pop_front(node_t **head)
{
    if (!head || !(*head))
        return NULL;

    void *data = (*head)->data;
    node_t *temp = *head;
    *head = (*head)->next;

    free(temp);
    return data;
}

void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *))
{
    if (!head || !(*head) || !comparator)
        return;

    node_t *first = *head, *second = first->next;
    
    while (second && second->next)
    {
        if (!comparator(first->data, second->data))
        {
            first->next = second->next;
            free(second);
        }
        else
        {
            first = second;
        }
        second = first->next;
    }

    if (first->next && !comparator(first->data, second->data))
    {
        first->next = second->next;
        free(second);
    }
}
