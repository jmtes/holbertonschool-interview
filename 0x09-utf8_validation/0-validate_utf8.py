#!/usr/bin/python3


def validUTF8(data):
    firstBit = 1 << 7
    secondBit = 1 << 6

    currentBytes = 0

    for n in data:
        if not currentBytes:
            bitPointer = 1 << 7

            while bitPointer & n:
                currentBytes += 1
                bitPointer = bitPointer >> 1

            if not currentBytes:
                continue

            if not 1 < currentBytes <= 4:
                return False

        else:
            if (not (n & firstBit)) or (n & secondBit):
                return False

        currentBytes -= 1

    return currentBytes == 0
