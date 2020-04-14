#include "slide_line.h"

int slide_line(int *line, size_t size, int direction) {
  int *place_here = NULL;
  int *left = NULL;
  int *right = NULL;
  
  // if (!line || direction != SLIDE_LEFT || direction != SLIDE_RIGHT) {
  //   return (0);
  // }

  if (direction == SLIDE_LEFT) {
    place_here = line;
    left = place_here;

    while (left < line + (size - 1)) {
      while (*left == 0 && left < line + (size - 1)) {
        left++;
      }
      right = left + 1;
      while (right < line + (size)) {
        if (*right == *left) {
          *place_here = *left * 2;
          if (place_here != left) {
            *left = 0;
          }
          *right = 0;
          place_here++;
          break;
        } else {
          right++;
        }
      }
      // if (!*place_here && *left) {
      //   *place_here = *left;
      //   *left = 0;
      // }
      left++;
    }
    if (*(line + size - 1) && !*place_here) {
      *place_here = *(line + size - 1);
      *(line + size - 1) = 0;
    }
  }
  return (1);
}
