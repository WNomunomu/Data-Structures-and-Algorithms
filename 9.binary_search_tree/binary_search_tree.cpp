#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

struct Node {
  int key;
  Node *parent, *leftChild, *rightChild;
};

Node *root, *NIL;

void initialize() {
  NIL = (Node *)malloc(sizeof(Node));
  NIL->parent = NIL->leftChild = NIL->rightChild = NIL;
  root = NIL;
}

void insertNode(int key) {
  Node *parentCandidate = NIL;
  Node *x = root;
  Node *node;

  node = (Node *)malloc(sizeof(Node));

  node->key = key;
  node->leftChild = NIL;
  node->rightChild = NIL;

  while (x != NIL) {
    parentCandidate = x;
    if (node->key < x->key) {
      x = x->leftChild;
    }
    else if (x->key < node->key) {
      x = x->rightChild;
    }
  }

  node->parent = parentCandidate;

  if (parentCandidate == NIL) {
    root = node;
  }
  else {
    if (node->key < parentCandidate->key) {
      parentCandidate->leftChild = node;
    }
    else if (parentCandidate->key < node->key) {
      parentCandidate->rightChild = node;
    }
  }
}

void inorder(Node *node) {
  if (node == NIL) {
    return;
  }
  inorder(node->leftChild);
  cout << " " << node->key;
  inorder(node->rightChild);
}

void preorder(Node *node) {
  if (node == NIL) {
    return;
  }
  cout << " " << node->key;
  preorder(node->leftChild);
  preorder(node->rightChild);
}

void printTree(Node *root) {
  inorder(root);
  cout << "\n";
  preorder(root);
  cout << "\n";
}

void findNode(Node *node, int key) {
  if (node->key == key) {
    cout << "yes" << "\n";
    return;
  }
  if (node == NIL) {
    cout << "no" << "\n";
    return;
  }

  if (key < node->key) {
    findNode(node->leftChild, key);
  }
  else if (node->key < key) {
    findNode(node->rightChild, key);
  }
}

Node* findMinNode(Node *node) {
  Node *minNode = node;
  while (minNode->leftChild != NIL) {
    minNode = minNode->leftChild;
  }
  return minNode;
}

// これではダメ
// Node* findMinNode(Node *node) {
//   if (node == NIL) {
//     return node->parent;
//   }
//   findMinNode(node->leftChild);
// }

void deleteProcess(Node *node) {
  Node *parent = node->parent;

  if (node->leftChild == NIL && node->rightChild == NIL) {
    if (parent->leftChild == node) {
      parent->leftChild = NIL;
    }
    else {
      parent->rightChild = NIL;
    }
    node->parent = NIL;
  }

  else if (node->leftChild == NIL || node->rightChild == NIL) {
    if (parent->leftChild == node) {
      if (node->leftChild != NIL) {
        parent->leftChild = node->leftChild;
        node->leftChild->parent = parent;
      }
      else {
        parent->leftChild = node->rightChild;
        node->rightChild->parent = parent;
      }
    }
    else if (parent->rightChild == node) {
      if (node->leftChild != NIL) {
        parent->rightChild = node->leftChild;
        node->leftChild->parent = parent;
      }
      else {
        parent->rightChild = node->rightChild;
        node->rightChild->parent = parent;
      }
    }
  }

  else {
    Node *minNode = findMinNode(node->rightChild);
    
    if (minNode->parent->leftChild == minNode) {
      minNode->parent->leftChild = NIL;
    }
    else {
      minNode->parent->rightChild = NIL;
    }
    
    if (parent->leftChild == node) {
      parent->leftChild = minNode;
    }
    else {
      parent->rightChild = minNode;
    }
    minNode->parent = parent;

    minNode->leftChild = node->leftChild;
    minNode->rightChild = node->rightChild;
    
    node->leftChild->parent = minNode;
    node->rightChild->parent = minNode;
  }
}

void deleteNode(Node *node, int key) {
  if (node->key == key) {
    deleteProcess(node);
  }
  if (node == NIL) {
    return;
  }

  if (key < node->key) {
    deleteNode(node->leftChild, key);
  }
  else if (node->key < key) {
    deleteNode(node->rightChild, key);
  }
}

int main() {
  initialize();
  int n, key;
  string operation;
  cin >> n;
  rep(i, n) {
    cin >> operation;
    if (operation == "insert") {
      cin >> key;
      insertNode(key);
    }
    else if (operation == "print") {
      printTree(root);
    }
    else if (operation == "find") {
      cin >> key;
      findNode(root, key);
    }
    else if (operation == "delete") {
      cin >> key;
      deleteNode(root, key);
    }
  }

  return 0;
}
