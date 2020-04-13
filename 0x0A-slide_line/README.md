# 0x0A. 2048 (Single Line)

## Instructions
Reproduce the 2048 game mechanics on a single horizontal line.

Given an array of integers, one should be able to slide and merge it to the left or to the right. Identical numbers, if they are contiguous or separated by zeroes, should be merged.

* Write a function that slides and merges an array of integers.
* Prototype: `int slide_line(int *line, size_t size, int direction);`
* Where `line` points to an array of integers containing `size` elements that must be slid and merged to the direction represented by `direction`.
* `direction` can be either `SLIDE_LEFT` or `SLIDE_RIGHT`. If it is something else, the function should fail.
* Both macros `SLIDE_LEFT` and `SLIDE_RIGHT` must be defined in `slide_line.h`.
* Your function must return `1` upon success, `0` otherwise.
* You are not allowed to dynamically allocate memory.
