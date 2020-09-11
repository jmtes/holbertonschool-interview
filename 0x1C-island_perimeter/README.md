# 0x1C. Island Perimeter

## Instructions

Create a function `island_perimeter(grid)` that returns the perimeter of the island described in `grid`.

`grid` is a list of lists of integers, wherein:

- `0` represents water
- `1` represents land
- Each cell is a square with a side length of 1
- Cells are connected horizontally and vertically, but not diagonally

`grid` is rectangular with a max width and height of 100.

Other things to note:

- The grid is completely surrounded by water
- There can only ever be one island, if there is one.
- The island will not contain lakes.
