#include "sort.h"

/**
 * get_max - Get max value in array
 * @array: Pointer to array of ints
 * @size: Size of array
 *
 * Return: Max value in array
 */
int get_max(int *array, size_t size)
{
	int signed_size = (short)size;
	int max = 0;
	int i;

	for (i = 0; i < signed_size; i++)
		if (array[i] > max)
			max = array[i];

	return (max);
}

/**
 * counting_sort - Subroutine for radix sort
 * @array: Array of ints to sort
 * @size: Size of array to sort
 * @digit: The current digit to sort by
 *
 * Return: None
 */
void counting_sort(int *array, size_t size, int digit)
{
	int signed_size = (short)size;
	int *tmp = NULL;
	int count[10] = {0};
	int i;

	tmp = malloc(sizeof(int) * size);
	if (!tmp)
		return;

	for (i = 0; i < signed_size; i++)
		count[(array[i] / digit) % 10] += 1;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = size - 1; i >= 0; i--)
	{
		tmp[count[(array[i] / digit) % 10] - 1] = array[i];
		count[(array[i] / digit) % 10]--;
	}

	for (i = 0; i < signed_size; i++)
		array[i] = tmp[i];

	print_array(tmp, size);
	free(tmp);
}

/**
 * radix_sort - Sort array with radix sort algorithm
 * @array: Array of ints to sort
 * @size: Size of array
 *
 * Return: None
 */
void radix_sort(int *array, size_t size)
{
	int max = get_max(array, size);
	int digit;

	if (!array)
		return;

	for (digit = 1; max / digit > 0; digit *= 10)
		counting_sort(array, size, digit);
}
