#!/usr/bin/python3

def minOperations(n):
  count = 0
  for i in range(n // 2, 0, -1):
    print('inside for')
    print('n is {}, i is {}'.format(n, i))
    while n % i == 0 and i != 1:
      print('inside while')
      print('n is {}, i is {}'.format(n, i))
      if n // i == 2:
        count += 2
      else:
        count += 1
      n //= i
  return count
