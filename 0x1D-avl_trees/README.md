# 0x1D. AVL Trees

## Instructions

Write a function that checks if a binary tree is a valid AVL tree.

- Prototype: `int binary_tree_is_avl(const binary_tree_t *tree);`
- `tree` is a pointer to the root node of the tree to check
- Your function must return `1` if `tree` is an AVL tree and `0` if not
- If `tree` is `NULL`, return `0`

### Properties of an AVL tree

- An AVL tree is a BST
- The difference between the heights of the left and right subtress can be no larger than 1
- The left and right subtrees must also be BSTs
