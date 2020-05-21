const SkipListNode = {
  n: undefined, // integer
  index: undefined, // index of node
  next: undefined, // pointer to next node
  express: undefined // pointer to next node in express lane
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