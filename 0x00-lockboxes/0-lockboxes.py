#!/usr/bin/python3

def canUnlockAll(boxes):
  unlocked = {
    'to_check': set([0]),
    'checked': set()
  }

  while len(unlocked['to_check']):
    current_box = unlocked['to_check'].pop()
    for key in boxes[current_box]:
      if key not in unlocked['checked']:
        unlocked['to_check'].add(key)
    unlocked['checked'].add(current_box)
  
  if len(unlocked['checked']) == len(boxes):
    return True
  return False
