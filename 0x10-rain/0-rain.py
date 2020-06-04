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
            print(
                'Window is [{}, {}, {}]'.format(
                    walls[windowStart],
                    walls[windowMiddle],
                    walls[windowEnd]))
            if walls[windowStart] > walls[windowMiddle] < walls[windowEnd]:
                print('{} units of water were collected here'.format(min([walls[windowStart], walls[windowEnd]]) - walls[windowMiddle]))
                waterCollected += min([walls[windowStart], walls[windowEnd]]) - walls[windowMiddle]
            windowStart += 1
            windowEnd += 1

    return waterCollected
