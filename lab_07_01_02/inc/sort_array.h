#ifndef SORT_ARRAY_H
#define SORT_ARRAY_H

void mysort(void *base, size_t nmemb, size_t size, int (*compar)(const void*, const void*));
void swap(void *a, void *b, size_t size);
int compare_int(const void *left, const void *right);

#endif
