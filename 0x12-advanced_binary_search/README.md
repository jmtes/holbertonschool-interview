# 0x0C. Advanced Binary Search

## Task Instructions
Write a function that searches for a value in a sorted array of integers.
* Prototype: `int advanced_binary(int *array, size_t size, int value);`
* `array` is a pointer to the first element of the array.
* `size` is the number of elements in `array`.
* `value` is the value to search for.
* Your function must return the index where `value` is located.
* You can assume that `array` will be sorted in ascending order.
* If `value` is not present in the array or if `array`, return `-1`.
* If `array` is `NULL`, return `-1`.
* Every time you split the array, you have to print the subarray you're searching in.
* You must use recursion.
