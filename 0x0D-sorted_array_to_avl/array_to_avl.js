const BinaryTreeNode = {
  n: undefined,
  parent: undefined,
  left: undefined,
  right: undefined
};

function arrayToAVL (array, arraySize) {
  let mid;

  if (arraySize % 2 === 0) {
    mid = parseInt((arraySize / 2) - 1);
  } else {
    mid = parseInt(arraySize / 2);
  }

  const root = Object.create(BinaryTreeNode);
  root.n = array[mid];
  root.parent = null;

  root.left = arrayToAVLChildren(array.slice(0, mid), root);
  root.right = arrayToAVLChildren(array.slice(mid + 1), root);

  function arrayToAVLChildren (array, parentNode) {
    let mid;

    if (array.length % 2 === 0) {
      mid = parseInt((array.length / 2) - 1);
    } else {
      mid = parseInt(array.length / 2);
    }

    const newNode = Object.create(BinaryTreeNode);
    newNode.n = array[mid];

    if (newNode.n === undefined) {
      return;
    }

    newNode.parent = parentNode;

    if (array.length > 1) {
      newNode.left = arrayToAVLChildren(array.slice(0, mid), newNode);
      newNode.right = arrayToAVLChildren(array.slice(mid + 1), newNode);
    } else {
      newNode.left = undefined;
      newNode.right = undefined;
    }

    return newNode;
  }

  return root;
}

function printTreePreOrder (tree) {
  console.log(tree);
  if (tree.left !== undefined) {
    printTreePreOrder(tree.left);
  }
  if (tree.right !== undefined) {
    printTreePreOrder(tree.right);
  }
}

function main () {
  const array = [1, 2, 20, 21, 22, 32, 34, 47, 62, 68, 79, 84, 87, 91, 95, 98];
  const n = array.length;

  const tree = arrayToAVL(array, n);

  if (!tree) {
    console.log('Something went wrong.');
  } else {
    console.log('Success!');
    console.log(array);
    printTreePreOrder(tree);
  }
}

main();
