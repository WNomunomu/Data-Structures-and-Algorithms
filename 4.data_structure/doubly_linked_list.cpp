#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

static const int MAX = 1000000;
static const int NIL = -1;

struct Node {
  int key;
  Node* prev;
  Node* next;
};

Node* nil;

void initialize() {
  nil = (Node*)malloc(sizeof(Node));
  nil->prev = nil;
  nil->next = nil;
}

void insertNode(int x) {
  Node* node = (Node*)malloc(sizeof(Node));
  node->key = x;
  node->prev = nil;
  nil->next->prev = node; // 最初の insert、つまり nil しかない時には nil->prev に最初に insert した node (lastNode)が追加される。
  node->next = nil->next;
  nil->next = node;
}

Node* findNode(int x) {
  Node* node = nil->next;
  while (node != nil && node->key != x) {
    node = node->next;
  }
  return node;
}

void deleteNode(Node* node) {
  if (node == nil) return;
  node->prev->next = node->next;
  node->next->prev = node->prev;
  free(node);
}

void deleteFirst() {
  deleteNode(nil->next);
}

// nil->prev で取得できるので、findLast() は消去

// Node* findLast() {
//   Node* node = nil->next;
//   while (true) {
//     if (node->next == nil) {
//       return node;
//     }
//     node = node->next;
//   }
// }

void deleteLast() {
  deleteNode(nil->prev);
}

void printList() {
  Node* node = nil->next;
  while (true) {
    if (node->next == nil) {
      printf("%d\n", node->key);
      break;
    }
    else {
      printf("%d ", node->key);
    }
    node = node->next;
  }
}

int main() {
  int key, n;
  char operation[20];
  
  scanf("%d", &n);

  initialize();

  rep(i, n) {
    scanf("%s", operation);
    if (operation[0] == 'i') {
      scanf("%d", &key);
      insertNode(key);
    }
    else if (operation[6] == 'F') {
      deleteFirst();
    }
    else if (operation[6] == 'L') {
      deleteLast();
    }
    else {
      scanf("%d", &key);
      deleteNode(findNode(key));
    }
  }

  printList();

  return 0;
}
