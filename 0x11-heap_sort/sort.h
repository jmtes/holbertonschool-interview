#ifndef HEAP_SORT_H
#define HEAP_SORT_H

#include <stddef.h>

void print_array(const int *array, size_t size);
int find_parent_idx(int idx);
void swap_values(int *array, size_t size, int idx1, int idx2);
void max_heapify(int *array, size_t size);
void heap_sort(int *array, size_t size);

#endif
