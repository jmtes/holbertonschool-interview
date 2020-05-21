const SkipListNode = {
  n: undefined, // integer
  index: undefined, // index of node
  next: undefined, // pointer to next node
  express: undefined // pointer to next node in express lane
};

function linearSkip (list, val) {
  return SkipListNode;
}

function initExpress (list, size) {
  const step = parseInt(Math.sqrt(size));
  let save = list;

  for (let i = 0; i < size; ++i) {
    console.log(i);
    if (i % step === 0) {
      save.express = list;
      save = list;
    }
    if (list.next !== undefined) {
      list = list.next;
    } else {
      break;
    }
  }
}

function createSkipList (array, size) {
  let list;

  let sizeIter = size - 1;
  while (sizeIter) {
    const node = Object.create(SkipListNode);
    node.n = array[sizeIter];
    node.index = sizeIter;
    node.express = null;
    node.next = list;
    list = node;
    sizeIter--;
  }

  initExpress(list, size);
  return list;
}

function printSkipList (list) {
  let node;

  console.log('List:');
  node = list;
  while (node !== undefined) {
    console.log(`Index[${node.index}] = ${node.n}`);
    node = node.next;
  }

  console.log('Express Lane:');
  node = list;
  while (node !== null) {
    console.log(`Index[${node.index}] = ${node.n}`);
    node = node.express;
  }
}

function main () {
  const array = [0, 1, 2, 3, 4, 7, 12, 15, 18, 19, 23, 53, 61, 62, 76, 99];
  const size = array.length;

  const list = createSkipList(array, size);
  printSkipList(list);

  let val = 53;
  let res = linearSkip(list, val);
  console.log(`Found ${val} at ${res.index}`);

  val = 2;
  res = linearSkip(list, val);
  console.log(`Found ${val} at ${res.index}`);

  val = 999;
  res = linearSkip(list, val);
  console.log(`Found ${val} at ${res.index}`);
}

main();
