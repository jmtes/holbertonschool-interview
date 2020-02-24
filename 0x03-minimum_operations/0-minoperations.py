#!/usr/bin/python3


def minOperations(n):
    factors = []
    i = 2
    while n > 1:
        while n % i == 0:
            factors.append(i)
            n = n / i
        i += 1
    return sum(factors)
