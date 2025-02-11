#include<iostream>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

static const int NIL = -1;

struct Node {
  int parent;
  int leftChild;
  int rightSibiling;
};

void initialize(Node Tree[], int n) {
  rep(i, n) {
    Tree[i].parent = Tree[i].leftChild = Tree[i].rightSibiling = NIL;
  }
}

void setDepth(int id, int depth, int Depth[], Node Tree[]) {
  if (id != NIL) {
    Depth[id] = depth;
    setDepth(Tree[id].rightSibiling, depth, Depth, Tree);
    setDepth(Tree[id].leftChild, depth + 1, Depth, Tree);
  }
}

int findRoot(int n, Node Tree[]) {
  rep(i, n) {
    if (Tree[i].parent == NIL) {
      return i;
    }
  }
  return NIL;
}

void printTypeOfNode(Node node) {
  if (node.parent == NIL) {
    printf("root");
  }
  else if (node.leftChild == NIL) {
    printf("leaf");
  }
  else {
    printf("internal node");
  }
}

void printChildren(int id, Node Tree[]) {
  Node node = Tree[id];
  Node child = Tree[node.leftChild];
  if (node.leftChild == NIL) {
    printf("[]\n");
  }
  else {
    printf("[%d", node.leftChild);
    while (child.rightSibiling != NIL) {
      printf(", %d", child.rightSibiling);
      child = Tree[child.rightSibiling];
    }
    printf("]\n");
  }
}

void printNodeData(int id, Node Tree[], int Depth[]) {
    printf("node %d: parent = %d, depth = %d, ", id, Tree[id].parent, Depth[id]);
    printTypeOfNode(Tree[id]);
    printf(", ");
    printChildren(id, Tree);
}

int main() {
  int n;
  scanf("%d", &n);
  Node Tree[n];

  initialize(Tree, n);

  rep(i, n) {
    int id, k, child, prevChild;
    scanf("%d %d", &id, &k);
    rep(i, k) {
      scanf("%d", &child);
      if (i == 0) Tree[id].leftChild = child;
      Tree[child].parent = id;
      if (i != 0) Tree[prevChild].rightSibiling = child;
      prevChild = child;
    }
  }

  int Depth[n];
  int rootId = findRoot(n, Tree);
  setDepth(rootId, 0, Depth, Tree);

  rep (i, n) {
    printNodeData(i, Tree, Depth);
  }

  return 0;
}
