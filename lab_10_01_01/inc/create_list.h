#ifndef CREATE_LIST_H
#define CREATE_LIST_H

#include <stdlib.h>
#include "struct.h"

node_t *node_create(void *number);
node_t *list_add(node_t *head, node_t *temp);
void list_free(node_t *head);

#endif
