#ifndef EXECUTE_MODES_H
#define EXECUTE_MODES_H

#include <stdlib.h>

#include "struct.h"
#include "create_list.h"

node_t *find(node_t *head, const void *data, int (*comparator)(const void *, const void *));
void *pop_front(node_t **head);
void remove_duplicates(node_t **head, int (*comparator)(const void *, const void *));

#endif
