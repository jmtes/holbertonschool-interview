#include "sort.h"

int get_max(int *array, size_t size)
{
  int signed_size = (short)size;
  int max = 0;
  int i;

  for (i = 0; i < signed_size; i++)
    if (array[i] > max)
      max = array[i];

  return max;
}

void counting_sort(int *array, size_t size, int digit)
{
  int signed_size = (short)size;
  int *tmp = NULL;
  int count[10] = {0};
  int i;

  tmp = malloc(sizeof(int) * size);
  if (!tmp)
    return;

  for (i = 0; i < signed_size; i++)
    count[(array[i] / digit) % 10] += 1;

  for (i = 1; i < 10; i++)
    count[i] += count[i - 1];

  for (i = size - 1; i >= 0; i--)
  {
    tmp[count[(array[i] / digit) % 10] - 1] = array[i];
    count[(array[i] / digit) % 10]--;
  }

  for (i = 0; i < signed_size; i++)
    array[i] = tmp[i];

  print_array(tmp, size);
  free(tmp);
}

void radix_sort(int *array, size_t size)
{
  if (!array)
    return;

  int max = get_max(array, size);
  int digit;

  for (digit = 1; max / digit > 0; digit *= 10)
    counting_sort(array, size, digit);
}
