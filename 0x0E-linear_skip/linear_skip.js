const SkipListNode = {
  n: undefined, // integer
  index: undefined, // index of node
  next: undefined, // pointer to next node
  express: undefined // pointer to next node in express lane
};

function linkedListLength (list) {
  let len = 0;

  while (list) {
    len++;
    list = list.next;
  }

  return len;
}

function linearSkip (list, val) {
  let current = list;
  const lastIndex = linkedListLength(list) - 1;

  if (current) {
    while (current.express !== null && current.express.n < val) {
      console.log(`Value checked at index [${current.express.index}] = [${current.express.n}]`);

      current = current.express;
    }
    if (current.express) {
      console.log(`Value checked at index [${current.express.index}] = [${current.express.n}]`);
    }
    console.log(`Value found between indexes [${current.index}] and [${current.express ? current.express.index : lastIndex}]`);
    while (current) {
      console.log(`Value checked at index [${current.index}] = [${current.n}]`);
      if (current.n === val) {
        return current;
      }
      current = current.next;
    }
  }

  return SkipListNode;
}

function initExpress (list, size) {
  const step = parseInt(Math.sqrt(size));
  let save = list;

  if (size > 1) {
    for (let i = 0; i < size; i++) {
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
}

function createSkipList (array, size) {
  let head;
  let prevNode;
  let index = 0;

  if (size > 0) {
    array.forEach(value => {
      const node = Object.create(SkipListNode);
      node.n = value;
      node.index = index;
      node.express = null;

      if (head === undefined) {
        head = node;
      }
      if (prevNode !== undefined) {
        prevNode.next = node;
      }
      prevNode = node;
      index++;
    });

    initExpress(head, size);
  }

  return head;
}

function printSkipList (list) {
  if (list !== undefined) {
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
