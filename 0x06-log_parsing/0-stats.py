#!/usr/bin/python3
from sys import stdin

total_size = 0

status_codes = {
  '200': 0,
  '301': 0,
  '400': 0,
  '401': 0,
  '403': 0,
  '404': 0,
  '405': 0,
  '500': 0
}

sorted_keys = sorted(status_codes.keys())

def print_stats():
  print('File size: {}'.format(total_size))
  for key in sorted_keys:
    if status_codes[key]:
      print('{}: {}'.format(key, status_codes[key]))

i = 0

try:
  for line in stdin:
    split_line = line.split()
    status = split_line[7]
    file_size = split_line[8]
    status_codes[status] += 1
    total_size += int(file_size)
    i += 1
    if i == 10:
      print_stats()
      i = 0
except KeyboardInterrupt:
    print_stats()
