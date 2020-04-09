#!/usr/bin/python3


def validUTF8(data):
    invalid_chars = list(filter(lambda x: (x > 255), data))
    return False if len(invalid_chars) else True
