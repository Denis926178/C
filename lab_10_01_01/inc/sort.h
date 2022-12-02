#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include "struct.h"

int comparator(const void *left, const void *right);
node_t *sort(node_t *head, int (*comparator)(const void *, const void *));
void sorted_insert(node_t **head, node_t *element, int (*comparator)(const void *, const void *));

#endif
