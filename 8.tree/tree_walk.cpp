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

void preorder(int id, Node Tree[]) {
  printf(" %d", id);
  if (Tree[id].leftChild != NIL) preorder(Tree[id].leftChild, Tree);
  if (Tree[id].rightChild != NIL) preorder(Tree[id].rightChild, Tree);
}

void inorder(int id, Node Tree[]) {
  if (Tree[id].leftChild != NIL) inorder(Tree[id].leftChild, Tree);
  printf(" %d", id);
  if (Tree[id].rightChild != NIL) inorder(Tree[id].rightChild, Tree);
}

void postorder(int id, Node Tree[]) {
  if (Tree[id].leftChild != NIL) postorder(Tree[id].leftChild, Tree);
  if (Tree[id].rightChild != NIL) postorder(Tree[id].rightChild, Tree);
  printf(" %d", id);
}

int getRoot(int n, Node Tree[]) {
  rep(i, n) {
    if (Tree[i].parent == NIL) {
      return i;
    }
  }
  return NIL;
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

  int root = getRoot(n, Tree);

  if (root != NIL) {
    printf("Preorder\n");
    preorder(root, Tree);
    printf("\n");
    printf("Inorder\n");
    inorder(root, Tree);
    printf("\n");
    printf("Postorder\n");
    postorder(root, Tree);
    printf("\n");
  }
  
  return 0;
}
