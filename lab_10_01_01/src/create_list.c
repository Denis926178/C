#include "create_list.h"

node_t *node_create(void *number)
{
    node_t *temp = malloc(sizeof(node_t));

    if (temp)
    {
        temp->data = number;
        temp->next = NULL;
    }

    return temp;
}

node_t *list_add(node_t *head, node_t *temp)
{
    node_t *cur = head;

    if (!head)
        return temp;

    while (cur->next != NULL)
        cur = cur->next;

    cur->next = temp;

    return head;
}

void list_free(node_t *head)
{
    node_t *next;

    for (; head; head = next)
    {
        next = head->next;
        free(head);
    }
}
