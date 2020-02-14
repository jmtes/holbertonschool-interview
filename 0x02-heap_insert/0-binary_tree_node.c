#include "binary_trees.h"

/**
 * binary_tree_node - Add node to binary tree
 * @parent: Pointer to parent of new node
 * @value: Integer to be copied into node
 *
 * Return: Pointer to new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value) {
  binary_tree_t *new_node = NULL;

  new_node = malloc(sizeof(binary_tree_t));
  if (!new_node) {
    return (NULL);
  }

  new_node->n = value;
  new_node->parent = parent;
  return (new_node);
}
