#!/usr/bin/python3
''' Define rain() function. '''


def rain(walls):
    ''' Given a list of wall heights, calculate amount of water retained by
    them after it rains. '''

    waterCollected = 0

    if len(walls) >= 3:
        windowStart = 0
        windowEnd = 2

        while windowEnd < len(walls):
            windowMiddle = windowStart + 1
            if walls[windowStart] > walls[windowMiddle] < walls[windowEnd]:
                waterCollected += min([walls[windowStart],
                                       walls[windowEnd]]) - walls[windowMiddle]
            windowStart += 1
            windowEnd += 1

    return waterCollected
