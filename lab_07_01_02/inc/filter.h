#ifndef FILTER_H
#define FILTER_H

#define ERROR_KEY_DATA          8
#define ERROR_MEMORY            5
#define ERROR_ALL_NUMBERS_NEG   6

int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);

#endif
