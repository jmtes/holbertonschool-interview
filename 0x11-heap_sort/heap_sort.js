function findParentIdx(idx) {
  if (idx % 2 === 0) idx = idx - 2;
  else idx = idx - 1;
  return idx / 2;
}

function swapValues(array, idx1, idx2) {
  tmp = array[idx1];
  array[idx1] = array[idx2];
  array[idx2] = tmp;
  console.log(array);
}

function maxHeapify(array, len) {
  const idxLastParent = findParentIdx(len - 1);
  console.log(idxLastParent);

  let idx = idxLastParent;
  let tmp;

  while (idx >= 0) {
    const left = 2 * idx + 1;
    const right = 2 * idx + 2;

    console.log(
      `IDX: ${array[idx]}, LEFT: ${array[left]}, RIGHT: ${array[right]}`
    );
    if (right < len && array[idx] < array[right]) {
      console.log(`Swapping ${array[idx]} and ${array[right]}`);
      swapValues(array, idx, right);
      idx = idxLastParent;
    } else if (array[idx] < array[left]) {
      console.log(`Swapping ${array[idx]} and ${array[left]}`);
      swapValues(array, idx, left);
      idx = idxLastParent;
    } else {
      idx--;
    }
  }
}

function heapSort(array, len) {
  if (len >= 2) {
    maxHeapify(array, len);
    swapValues(array, 0, len - 1);
    heapSort(array, len - 1);
  }
}

function main() {
  const array = [19, 48, 99, 71, 13, 52, 96, 73, 86, 7];
  const len = array.length;

  console.log('Original array:');
  console.log(array);

  console.log('Sorting...');
  heapSort(array, len);

  console.log('Sorted array:');
  console.log(array);
}

main();
