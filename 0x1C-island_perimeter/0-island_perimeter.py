#!/usr/bin/python3
''' This module defines the island_perimeter function.

    Attributes:
        island_perimeter - Function that returns the perimeter of an island.
'''


def island_perimeter(grid):
    ''' Finds perimeter of an island defined in grid.

        Args:
            grid - List of lists of integers that are either 1 or 0, with 1
                denoting a land space and 0 denoting a water space.
    '''
    grid = [[0] + row + [0] for row in grid]
    bl = max([len(row) for row in grid])
    bordertop = [[0 for i in range(bl)]]
    borderbot = [0 for i in range(bl)]
    bordertop.extend(grid)
    bordertop.append(borderbot)
    p = 0
    for i in range(1, len(bordertop)):
        for j in range(1, len(bordertop[i])):
            if bordertop[i][j] == 1:
                if bordertop[i - 1][j] == 0:
                    p += 1
                if bordertop[i][j + 1] == 0:
                    p += 1
                if bordertop[i + 1][j] == 0:
                    p += 1
                if bordertop[i][j - 1] == 0:
                    p += 1
    return p
