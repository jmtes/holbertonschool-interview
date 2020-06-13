#include "sort.h"

/**
 * find_parent_idx - Find parent of index in heapified array
 *
 * @idx: Index to find parent of
 *
 * Return: Index of parent of idx
 */
int find_parent_idx(int idx)
{
	if (idx % 2 == 0)
		idx = idx - 2;
	else
		idx = idx - 1;
	return (idx / 2);
}

/**
 * swap_values - Swap values in an array
 *
 * @array: Pointer to array of integers
 * @size: Size of array
 * @idx1: One of the indices to swap
 * @idx2: The other index to swap
 */
void swap_values(int *array, size_t size, int idx1, int idx2)
{
	int tmp = array[idx1];

	array[idx1] = array[idx2];
	array[idx2] = tmp;
	print_array(array, size);
}

/**
 * max_heapify - Make array into a max heap
 *
 * @array: Pointer to array of integers
 * @size: Size of array
 */
void max_heapify(int *array, size_t size)
{
	int idx_last_parent = find_parent_idx(size - 1);
	int idx = idx_last_parent;
	size_t left, right;

	while (idx >= 0)
	{
		left = 2 * idx + 1;
		right = 2 * idx + 2;

		if (right < size && array[idx] < array[right])
		{
			swap_values(array, size, idx, right);
			idx = idx_last_parent;
		} else if (array[idx] < array[left])
		{
			swap_values(array, size, idx, left);
			idx = idx_last_parent;
		} else
		{
			idx--;
		}

	}
}

/**
 * heap_sort - Sort array using heap sort algorithm
 *
 * @array: Pointer to array of integers
 * @size: Size of array
 */
void heap_sort(int *array, size_t size)
{
	if (size >= 2)
	{
		max_heapify(array, size);
		swap_values(array, size, 0, size - 1);
		heap_sort(array, size - 1);
	}
}
