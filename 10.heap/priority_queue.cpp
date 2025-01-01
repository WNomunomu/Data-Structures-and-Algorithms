#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define MAX 2000000
#define NIL -1
#define rep(i, n) for (int i = 0; i < n; i++)

int left(int i) {
  return 2 * i + 1;
}

int right(int i) {
  return 2 * i + 2;
}


void insertKey(int PriorityQueue[], int key, int *priorityQueueEnd) {
  if (key < 1) return;
  (*priorityQueueEnd)++;
  PriorityQueue[*priorityQueueEnd] = key;

  int keyIndex = *priorityQueueEnd;

  while (keyIndex > 0 && PriorityQueue[keyIndex] > PriorityQueue[(keyIndex - 1) / 2]) {
    int parentIndex = (keyIndex - 1) / 2;
    swap(PriorityQueue[keyIndex], PriorityQueue[parentIndex]);
    keyIndex = parentIndex;
  }
}

// void maxHeapify(int H[], int i, int numberOfNode) {
//   int node = H[i];
//   int leftChild, rightChild;
//   int largest;

//   if (left(i) < numberOfNode) {
//     leftChild = H[left(i)];
//   }
//   else {
//     leftChild = NIL;
//   }
//   if (right(i) < numberOfNode) {
//     rightChild = H[right(i)];
//   }
//   else {
//     rightChild = NIL;
//   }

//   if (node > leftChild && node > rightChild) {
//     largest = i;
//   }
//   else {
//     if (leftChild > node && leftChild > rightChild) {
//       largest = left(i);
//     }
//     else if (rightChild > node && rightChild > leftChild) {
//       largest = right(i);
//     }
//     swap(H[largest], H[i]);
//     maxHeapify(H, largest, numberOfNode);
//   }
// }

void maxHeapify(int H[], int i, int numberOfNode) {
  int largest = i;
  int leftChild = left(i);
  int rightChild = right(i);

  if (leftChild < numberOfNode && H[leftChild] > H[largest]) {
    largest = leftChild;
  }
  if (rightChild < numberOfNode && H[rightChild] > H[largest]) {
    largest = rightChild;
  }

  if (largest != i) {
    swap(H[i], H[largest]);
    maxHeapify(H, largest, numberOfNode);
  }
}


void extractKey(int PriorityQueue[], int *priorityQueueEnd) {
  cout << PriorityQueue[0] << endl;
  PriorityQueue[0] = PriorityQueue[*priorityQueueEnd];
  PriorityQueue[*priorityQueueEnd] = NIL;
  maxHeapify(PriorityQueue, 0, *priorityQueueEnd);
  (*priorityQueueEnd)--;
}

int main() {
  string operation = "none";
  int PriorityQueue[MAX];
  int priorityQueueEnd = -1;
  while (operation != "end") {
    cin >> operation;
    if (operation == "insert") {
      int key;
      cin >> key;
      insertKey(PriorityQueue, key, &priorityQueueEnd);
    }
    else if (operation == "extract") {
      extractKey(PriorityQueue, &priorityQueueEnd);
    }
  }

  return 0;
}
