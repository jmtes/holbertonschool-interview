const BinaryTreeNode = {
  n: undefined,
  parent: undefined,
  left: undefined,
  right: undefined
};

function main (array) {
  let root;
  let mid;

  if (array.length % 2 === 0) {
    mid = parseInt((array.length / 2) - 1);
  } else {
    mid = parseInt(array.length / 2);
  }
  console.log(array[mid]);

  root = Object.create(BinaryTreeNode);
  root.n = array[mid];
  root.parent = null;
  console.log(root);

  root.left = arrayToAVL(array.slice(0, mid), root);
  root.right = arrayToAVL(array.slice(mid + 1), root);

  function arrayToAVL (array, parentNode) {
    console.log('inside arrayToAVL');

    let newNode;
    let mid;

    if (array.length % 2 === 0) {
      mid = parseInt((array.length / 2) - 1);
    } else {
      mid = parseInt(array.length / 2);
    }
    console.log(array[mid]);

    newNode = Object.create(BinaryTreeNode);
    newNode.n = array[mid];
    newNode.parent = parentNode;
    console.log(newNode);

    if (array.length > 1) {
      newNode.left = arrayToAVL(array.slice(0, mid), newNode);
      newNode.right = arrayToAVL(array.slice(mid + 1), newNode);
    } else {
      newNode.left = undefined;
      newNode.right = undefined;
    }

    return newNode;
  }

  console.log(root);
}
