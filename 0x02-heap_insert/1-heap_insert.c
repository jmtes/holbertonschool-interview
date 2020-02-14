#include "binary_trees.h"

/*
 * heap_insert - Insert value into max binary heap
 * @root: Pointer to address of heap root
 * @value: Integer to store in node
 *
 * Return: Pointer to inserted node
 */
heap_t *heap_insert(heap_t **root, int value) {
	if (!root) {
		printf("Pointer to address of root is null\n");
		return (NULL);
	}
	if (!*root) {
		printf("Address of root is null\n");
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	return (NULL);
}
