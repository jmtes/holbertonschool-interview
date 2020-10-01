#!/usr/bin/python3
''' Create a Pascal Triangle. '''


def pascal_triangle(n):
    ''' Create a pascal triangle of size n represented as a matrix. '''
    rows = []

    for i in range(1, n + 1):
        if i == 1:
            rows.append([1])
        elif i == 2:
            rows.append([1, 1])
        else:
            prev_row = rows[i - 2]
            new_row = []
            for j in range(len(prev_row) - 1):
                new_row.append(prev_row[j] + prev_row[j + 1])
            rows.append([1] + new_row + [1])

    return rows
