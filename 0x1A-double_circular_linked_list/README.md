# 0x1A. Circular Doubly Linked List

## Instructions
Create a source file `0-add_node.c` that contains the following functions:

Add a new node to the end of a circular doubly linked list.
* Prototype: `List *add_node_end(List **list, char *str);`

Add a new node to the beginning of a circular doubly linked list:
* Prototype: `List *add_node_begin(List **list, char *str);`

For both functions:
* `list` is the list to modify and `str` is the string to copy into the new node
* Return the address of the new node or `NULL` on failure
