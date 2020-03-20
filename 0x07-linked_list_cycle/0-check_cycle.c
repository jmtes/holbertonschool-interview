#include "lists.h"

/**
 * check_cycle - Check if singly linked list has a cycle
 * @list: Pointer to linked list
 *
 * Return: 1 if list has a cycle, 0 otherwise
 */
int check_cycle(listint_t *list)
{
	listint_t *slow = NULL;
	listint_t *fast = NULL;

	if (!list)
	{
		return (0);
	}

	slow = list;
	fast = list;

	while (slow->next && fast->next->next)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return (1);
		}
	}

	return (0);
}
