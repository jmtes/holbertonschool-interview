const printArray = (array: number[], length: number): string => {
  return array.join(', ');
};

const merge = (array: number[], left: number[], right: number[]) => {
  let i: number, j: number, k: number;
  i = j = k = 0;

  console.log('Merging...');
  console.log(`[left]: ${printArray(left, left.length)}`);
  console.log(`[right]: ${printArray(right, right.length)}`);

  while (i < left.length && j < right.length) {
    if (left[i] < right[j]) {
      array[k] = left[i];
      i += 1;
    } else {
      array[k] = right[j];
      j += 1;
    }
    k += 1;
  }

  while (i < left.length) {
    array[k] = left[i];
    i += 1;
    k += 1;
  }

  while (j < right.length) {
    array[k] = right[j];
    j += 1;
    k += 1;
  }

  console.log(`[Done]: ${printArray(array, left.length + right.length)}`);
};

const mergeSort = (array: number[]): void => {
  // An element with one or fewer elements is already sorted
  if (array.length < 2) return;

  // Find midpoint
  const mid = Math.floor(array.length / 2);

  // Split array into halves
  const left: number[] = array.slice(0, mid);
  const right: number[] = array.slice(mid, array.length);

  mergeSort(left);
  mergeSort(right);

  merge(array, left, right);
};

const main = (): number => {
  const array: number[] = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7];
  const n: number = array.length;

  printArray(array, n);
  mergeSort(array);
  printArray(array, n);

  return 0;
};

main();
