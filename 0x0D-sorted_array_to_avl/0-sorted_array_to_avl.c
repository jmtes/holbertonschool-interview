#include <stdlib.h>
#include "binary_trees.h"

/**
 * helper - Generate children of AVL tree root
 *
 * @array: Pointer to subarray of array passed to sorted_array_to_avl
 * @size: Size of subarray
 * @parent: Parent of node to be created
 *
 * Return: Pointer to new tree node
 */
avl_t *helper(int *array, size_t size, avl_t *parent)
{
	avl_t *new_node = NULL;
	int mid;

	if (size)
	{
		mid = size / 2;
		if (size % 2 == 0)
			mid--;

		new_node = malloc(sizeof(avl_t));
		if (!new_node)
			return (NULL);

		new_node->n = array[mid];
		new_node->parent = parent;

		if (size > 1)
		{
			new_node->left = helper(array, mid, new_node);
			new_node->right = helper(array + mid + 1, size - mid - 1, new_node);
		}
		else
		{
			new_node->left = NULL;
			new_node->right = NULL;
		}

		return (new_node);
	}

	return (NULL);
}

/**
 * sorted_array_to_avl - Generate AVL tree from an array
 *
 * @array: Sorted array from which to build tree
 * @size: Size of array
 *
 * Return: Pointer to root of generated tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	int mid;

	if (!array)
		return (NULL);

	mid = size / 2;
	if (size % 2 == 0)
		mid--;

	root = malloc(sizeof(avl_t));
	if (!root)
		return (NULL);
	root->n = array[mid];
	root->parent = NULL;

	root->left = helper(array, mid, root);
	root->right = helper(array + mid + 1, size - mid - 1, root);

	return (root);
}
