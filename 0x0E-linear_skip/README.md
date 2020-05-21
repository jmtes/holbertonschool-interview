# 0x0E. Linear Search in Skip List

## Task Instructions
Write a function that searches for a vaue in a sorted skip list of integers.
* Prototype: `skiplist_t *linear_skip(skiplist_t *list, int value);`
* Where `list` is a pointer to the head of the skip list to search in and `value` is the value to search for
* A node of the express lane is place in every index which is a multiple of the square root of the size of the list
* You can assume that `list` will be sorted in ascending order.
* Your function must return a pointer to the first node containing `value`.
* If `value` is not present in `list` or if `head` is `NULL`, your function must return `NULL`.
* Every time you compare a value in the list to `value`, you have to print the value.
