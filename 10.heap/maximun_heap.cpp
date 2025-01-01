#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define NIL -1
#define rep(i, n) for (int i = 0; i < n; i++)

int parent(int i) {
  return i / 2;
}

int left(int i) {
  return i * 2;
}

int right(int i) {
  return i * 2 + 1;
}

void maxHeapify(int H[], int i, int numberOfNode) {
  int node = H[i];
  int leftChildren, rightChildren;
  int largest;
  if (left(i) <= numberOfNode) {
    leftChildren = H[left(i)];
  }
  else {
    leftChildren = NIL;
  }
  if (right(i) <= numberOfNode) {
    rightChildren = H[right(i)];
  }
  else {
    rightChildren = NIL;
  }

  if (node > leftChildren && node > rightChildren) {
    largest = i; 
  }
  if (leftChildren > node && leftChildren > rightChildren) {
    swap(H[i], H[left(i)]);
    largest = left(i);
    maxHeapify(H, largest, numberOfNode);
  }
  else if (rightChildren > node && rightChildren > leftChildren) {
    swap(H[i], H[right(i)]);
    largest = right(i);
    maxHeapify(H, largest, numberOfNode);
  }

}

void buildMaxHeap(int H[], int numberOfNode) {
  for (int i = numberOfNode / 2; i > 0; i--) {
    maxHeapify(H, i, numberOfNode);
  }
}

int main() {
  int n;
  cin >> n;
  // heap の性質を利用するために、1 から配列をスタートさせている。
  int H[n + 1];
  for (int i = 1; i < n + 1; i++) cin >> H[i];

  buildMaxHeap(H, n);

  for (int i = 1; i < n + 1; i++) cout << " " << H[i];
  
  cout << endl;

  return 0;
}
