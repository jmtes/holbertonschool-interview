interface Buckets {
  [propname: number]: number[];
}

const countingSort = (
  array: number[],
  currentDigit: number,
  digits: number
): number[] => {
  if (currentDigit <= digits) {
    const buckets: Buckets = {};

    array.forEach((val) => {
      const bucket: number = Math.floor(
        (val / Math.pow(10, currentDigit - 1)) % 10
      );

      if (buckets[bucket] === undefined) buckets[bucket] = [];
      buckets[bucket].push(val);
    });

    array = [];

    for (let bucket of Object.keys(buckets)) {
      array = array.concat(buckets[bucket]);
    }

    printArray(array);

    array = countingSort(array, currentDigit + 1, digits);
  }
  return array;
};

const radixSort = (array: number[]): number[] => {
  const max: number = Math.max(...array);
  const digits: number = max.toString().length;

  return countingSort(array, 1, digits);
};

const printArray = (array: number[]): void => {
  console.log(array.join(', '));
};

const main = (): void => {
  let array: number[] = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7];

  printArray(array);
  array = radixSort(array);
  printArray(array);
};

main();
