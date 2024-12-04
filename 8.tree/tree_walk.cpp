#include<iostream>
using namespace std;

#define MAX 100005
#define NIL -1
#define rep(i, n) for (int i = 0; (i) < (n); ++(i))

struct Node {
  int parentId;
  int rightChildId;
  int leftChildId;
};

Node Tree[MAX];

void preorderTreeWalk(int nodeId) {
  Node node = Tree[nodeId];
  cout << " " << nodeId;
  if (node.leftChildId != NIL) preorderTreeWalk(node.leftChildId);
  if (node.rightChildId != NIL) preorderTreeWalk(node.rightChildId);
}

void inorderTreeWalk(int nodeId) {
  Node node = Tree[nodeId];
  if (node.leftChildId != NIL) inorderTreeWalk(node.leftChildId);
  cout << " " << nodeId;
  if (node.rightChildId != NIL) inorderTreeWalk(node.rightChildId);
}

void postorderTreeWalk(int nodeId) {
  Node node = Tree[nodeId];
  if (node.leftChildId != NIL) postorderTreeWalk(node.leftChildId);
  if (node.rightChildId != NIL) postorderTreeWalk(node.rightChildId);
  cout << " " << nodeId;
}

void printTreeOrder(int rootId) {
  cout << "Preorder" << "\n";
  preorderTreeWalk(rootId);
  cout << "\n";
  cout << "Inorder" << "\n";
  inorderTreeWalk(rootId);
  cout << "\n";
  cout << "Postorder" << "\n";
  postorderTreeWalk(rootId);
  cout << "\n";
}

int main() {
  int n, nodeId, leftChildId, rightChildId, rootId;

  cin >> n;

  rep(i, n) {
    Tree[i].parentId = Tree[i].rightChildId = Tree[i].leftChildId = NIL;
  }

  rep(i, n) {
    cin >> nodeId >> leftChildId >> rightChildId;
    Tree[nodeId].rightChildId = rightChildId;
    Tree[nodeId].leftChildId = leftChildId;
    if (rightChildId != NIL) Tree[rightChildId].parentId = nodeId; 
    if (leftChildId != NIL) Tree[leftChildId].parentId = nodeId;
  }

  rep(i, n) {
    if (Tree[i].parentId == NIL) rootId = i;
  }

  printTreeOrder(rootId);

  return 0;
}

