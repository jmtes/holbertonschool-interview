#!/usr/bin/python3


def canUnlockAll(boxes):
    to_check = set([0])
    checked = set()

    while len(to_check):
        current_box = to_check.pop()
        for key in boxes[current_box]:
            if key not in checked:
                to_check.add(key)
        checked.add(current_box)

    if len(checked) == len(boxes):
        return True
    return False
