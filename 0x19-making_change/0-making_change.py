#!/usr/bin/python3
''' Define makeChange function. '''


def makeChange(coins, total):
    ''' Determine fewest number of coins needed to make amount `total`.

        Positional arguments:
        coins -- list of coin denominations
        total -- the total amount to make

        Return: Fewest amount of coins needed to make `total`, -1 if impossible
        to do so '''

    coins.sort(reverse=True)
    num_coins = 0

    for coin in coins:
        if total % coin < total:
            num_coins += total // coin
            total = total % coin

    return num_coins if total == 0 else -1
