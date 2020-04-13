#include "slide_line.h"

int slide_line(int *line, size_t size, int direction) {
  int *place_here = NULL;
  int *left = NULL;
  int *right = NULL;
  int i;
  
  // if (!line || direction != SLIDE_LEFT || direction != SLIDE_RIGHT) {
  //   return (0);
  // }

  if (direction == SLIDE_LEFT) {
    place_here = line;
    left = place_here;

    i = 0;

    while (left < line + (size - 1)) {
      printf(" i is %d\n", i);
      while (*left == 0 && left < line + (size - 1)) {
        printf("left is 0\n");
        i++;
        left++;
      }
      right = left + 1;
      while (right < line + (size)) {
        if (*right == *left) {
          printf("we got em\n");
          *place_here = *left * 2;
          if (place_here != left) {
            *left = 0;
          }
          *right = 0;
          place_here++;
          // left = place_here;
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
      i++;
    }
    printf("loop done\n");
    if (*(line + size - 1) && !*place_here) {
      printf("last value is not 0. it is %d\n", *(line + size - 1));
      *place_here = *(line + size - 1);
      *(line + size - 1) = 0;
    }
  }

  printf("%d\n", i);
  return (1);
}
