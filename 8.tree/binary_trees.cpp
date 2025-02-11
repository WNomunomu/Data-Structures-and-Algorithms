#include<iostream>

using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

#define NIL -1

struct Node {
  int parent, leftChild, rightChild;
};

void initialize(Node Tree[], int n) {
  rep(i, n) {
    Tree[i].leftChild = Tree[i].rightChild = Tree[i].parent = NIL;
  }
}

int getRoot(Node Tree[], int n) {
  rep(i, n) {
    if (Tree[i].parent == NIL) {
      return i;
    }
  }
  return NIL;
}

void setDepth(int id, int depth, int Depth[], Node Tree[]) {
  if (id != NIL) {
    Depth[id] = depth;
    setDepth(Tree[id].leftChild, depth + 1, Depth, Tree);
    setDepth(Tree[id].rightChild, depth + 1, Depth, Tree);
  }
}

int setHeight(int id, int Height[], Node Tree[]) {
  int h1 = 0;
  int h2 = 0;

  if (Tree[id].leftChild != NIL) {
    h1 = setHeight(Tree[id].leftChild, Height, Tree) + 1;
  }
  if (Tree[id].rightChild != NIL) {
    h2 = setHeight(Tree[id].rightChild, Height, Tree) + 1;
  }

  return Height[id] = max(h1, h2);
}

int getSibling(int id, Node Tree[]) {
  Node node = Tree[id];
  if (node.parent == NIL) return NIL;
  Node parent = Tree[node.parent];
  if (id == parent.leftChild) {
    return parent.rightChild;
  }
  else {
    return parent.leftChild;
  }
}

int getDegree(int id, Node Tree[]) {
  Node node = Tree[id];
  if (node.leftChild == NIL && node.rightChild == NIL) {
    return 0;
  }
  else if (node.leftChild != NIL && node.rightChild != NIL) {
    return 2;
  }
  else {
    return 1;
  }
}

string getNodeType(int id, Node Tree[]) {
  Node node = Tree[id];
  if (node.parent == NIL) {
    return "root";
  }
  else if (node.leftChild == NIL && node.rightChild == NIL) {
    return "leaf";
  }
  else {
    return "internal node";
  }
}

void printNodeData(int id, int Height[], int Depth[], Node Tree[]) {
  int parent = Tree[id].parent;
  int sibling = getSibling(id, Tree);
  int degree = getDegree(id, Tree);
  string nodeType = getNodeType(id, Tree);
  printf("node %d: parent = %d, sibling = %d, degree = %d, depth = %d, height = %d, %s\n", id, parent, sibling, degree, Depth[id], Height[id], nodeType.c_str());
}

int main() {
  int n;
  scanf("%d", &n);
  Node Tree[n];
  int Depth[n], Height[n];
  int id, leftChild, rightChild;

  initialize(Tree, n);

  rep(i, n) {
    scanf("%d %d %d", &id, &leftChild, &rightChild);
    Tree[id].leftChild = leftChild;
    Tree[id].rightChild = rightChild;
    Tree[leftChild].parent = Tree[rightChild].parent = id;
  }

  int root = getRoot(Tree, n);

  setDepth(root, 0, Depth, Tree);

  setHeight(root, Height, Tree);

  rep(i, n) {
    printNodeData(i, Height, Depth, Tree);
  }

  return 0;
}
