#include "binary_trees.h"

heap_t *root_not_full(heap_t **root, int value) {
	if (!(*root)->left) {
		printf("Root has no left child\n");
		(*root)->left = binary_tree_node(*root, value);
		return ((*root)->left);
	} else {
		printf("Root has no right child\n");
		(*root)->right = binary_tree_node(*root, value);
		return ((*root)->right);
	}
}

heap_t *swap_nodes(heap_t **root, int value) {
	heap_t *new_node = malloc(sizeof(heap_t));
	if (!new_node) {
		return (NULL);
	}

	new_node->n = value;

	if ((*root)->left && !(*root)->right) {
		new_node->left = (*root)->left;
		new_node->right = *root;
		new_node->parent = (*root)->parent;
		new_node->left->parent = new_node;
		new_node->right->parent = new_node;
		new_node->right->left = NULL;
		*root = new_node;
		return (new_node);
	}

	if (!(*root)->left) {
		new_node->left = *root;
	} else if (!(*root)->right) {
		new_node->right = *root;
	}
	new_node->parent = (*root)->parent;
	(*root)->parent = new_node;
	return (new_node);
}

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
		// printf("Address of root is null\n");
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	if (value > (*root)->n) {
		*root = swap_nodes(root, value);
		return (*root);
	}
	if (!((*root)->left && (*root)->right)) {
		return root_not_full(root, value);
	}
	heap_t *left = heap_insert(&((*root)->left), value);
	if (left) {
		return (left);
	}
	heap_t *right = heap_insert(&((*root)->right), value);
	if (right) {
		return (right);
	}
	return (NULL);
}
