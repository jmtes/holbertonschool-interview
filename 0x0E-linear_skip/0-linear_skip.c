#include "search.h"

/**
 * linked_list_len - Get length of linked list
 *
 * @list: Pointer to head of linked list
 *
 * Return: Length of linked list
 */
size_t linked_list_len(skiplist_t *list)
{
	int len = 0;

	while (list)
	{
		len++;
		list = list->next;
	}

	return (len);
}

/**
 * linear_skip - Perform linear search in skip list
 *
 * @list: Pointer to head of skip list
 * @value: Value to search for in list
 *
 * Return: Pointer to first node found containing value, NULL otherwise.
 */
skiplist_t *linear_skip(skiplist_t *list, int value)
{
	skiplist_t *current = list;
	size_t lastIndex;

	if (current)
	{
		lastIndex = linked_list_len(list) - 1;

		while (current->express && current->express->n < value)
		{
			printf("Value checked at index [%lu] = [%d]\n", current->express->index,
					current->express->n);
			current = current->express;
		}

		if (current->express)
			printf("Value checked at index [%lu] = [%d]\n", current->express->index,
					current->express->n);

		printf("Value found between indexes [%lu] and [%lu]\n", current->index,
				current->express ? current->express->index : lastIndex);

		while (current)
		{
			printf("Value checked at index [%lu] = [%d]\n", current->index, current->n);

			if (current->n == value)
				return (current);

			current = current->next;
		}
	}

	return (NULL);
}
