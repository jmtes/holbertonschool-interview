#!/usr/bin/python3


def canUnlockAll(boxes):
    to_check = set([0])
    checked = set()

    while len(to_check) and len(boxes):
        current_box = to_check.pop()
        for key in boxes[current_box]:
            if key not in checked and key < len(boxes):
                to_check.add(key)
        checked.add(current_box)

    return True if len(checked) == len(boxes) else False
