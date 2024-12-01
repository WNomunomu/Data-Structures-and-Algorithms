#include<iostream>
using namespace std;

#define MAX 100005
#define NIL -1
#define rep(i, n) for (int i = 0; (i) < (n); ++(i))

struct Node { int parentId, leftChildId, rightChildId; };

Node Tree[MAX];
int n, Depth[MAX], Height[MAX];

void printNodeType(int nodeId) {
  Node node = Tree[nodeId];
  if (node.parentId == NIL) cout << "root";
  else if (node.leftChildId == NIL && node.rightChildId == NIL) cout << "leaf";
  else cout << "internal node";
}

int getDegree(int nodeId) {
  Node node = Tree[nodeId];
  int degree;
  if (node.leftChildId == NIL && node.rightChildId == NIL) {
    degree = 0;
  }
  else if (node.leftChildId != NIL && node.rightChildId != NIL) {
    degree = 2;
  }
  else {
    degree = 1;
  }

  return degree;
}

int getSibling(int nodeId) {
  Node node = Tree[nodeId];
  if (node.parentId == NIL) {
    return NIL;
  }
  Node parentNode = Tree[node.parentId];
  int siblingId;

  if (parentNode.leftChildId == nodeId) {
    siblingId = parentNode.rightChildId;
  }
  else if (parentNode.rightChildId == nodeId) {
    siblingId = parentNode.leftChildId;
  }
  return siblingId;
}

void printTree(int nodeId) {
  Node node = Tree[nodeId];
  int siblingId = getSibling(nodeId);
  int degree = getDegree(nodeId);
  cout << "node " << nodeId << ": ";
  cout << "parent = " << node.parentId << ", ";
  cout << "sibling = " << siblingId << ", ";
  cout << "degree = " << degree << ", ";
  cout << "depth = " << Depth[nodeId] << ", ";
  cout << "height = " << Height[nodeId] << ", ";
  printNodeType(nodeId);
  cout << "\n";
}

void setDepth(int nodeId, int depth = 0) {
  Node node = Tree[nodeId];
  Depth[nodeId] = depth;
  if (node.leftChildId != NIL) setDepth(node.leftChildId, depth + 1);
  if (node.rightChildId != NIL) setDepth(node.rightChildId, depth + 1); // else if ではダメ（どっちも計算させたいため）
}

int setHeight(int nodeId) {
  Node node = Tree[nodeId];
  int leftHeight = 0;
  int rightHeight = 0;

  if (node.leftChildId != NIL) {
    leftHeight = setHeight(node.leftChildId) + 1;
  }
  if (node.rightChildId != NIL) {
    rightHeight = setHeight(node.rightChildId) + 1;
  }

  return Height[nodeId] = ( leftHeight > rightHeight ? leftHeight : rightHeight);
}

int main() {
  int n;
  int nodeId, rightChildId, leftChildId, rootId;
  cin >> n;

  rep(i, n) Tree[i].parentId = NIL;

  rep(i, n) {
    cin >> nodeId >> rightChildId >> leftChildId;
    Tree[nodeId].rightChildId = rightChildId;
    Tree[nodeId].leftChildId = leftChildId;
    if (rightChildId != NIL) Tree[rightChildId].parentId = nodeId; 
    if (leftChildId != NIL) Tree[leftChildId].parentId = nodeId;
  }

  rep(i, n) {
    if (Tree[i].parentId == NIL) {
      rootId = i;
    }
  }

  setDepth(rootId);
  setHeight(rootId);

  rep(i, n) {
    printTree(i);
  }

  return 0;
}
