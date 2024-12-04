#include<iostream>
using namespace std;

#define MAX 100005
#define NIL -1
#define rep(i, n) for (int i = 0; (i) < (n); ++(i))

void printArray(int A[], int n) {
  rep(i, n) {
    if (i != 0) {
      cout << " ";
    }
    cout << A[i];
    if (i == n - 1) {
      cout << "\n";
    }
  }
}

void insertionSort(int A[], int n) {
  int sorted = 0;
  int replaceNum;

  for (int i = 1; i < n; i++) {
    int key = A[i];
    replaceNum = i - 1;
    while (key < A[replaceNum] && replaceNum >= 0) {
      A[replaceNum + 1] = A[replaceNum];
      A[replaceNum] = key;
      replaceNum--;
    }
    printArray(A, n);
  }
}

int main() {
  int n, value;
  
  cin >> n;

  int A[n];

  rep(i, n) {
    cin >> value;
    A[i] = value;
  }

  A[n] = NIL;

  rep(i, n) {
    if (i != 0) {
      cout << " ";
    }
    cout << A[i];
    if (i == n - 1) {
      cout << "\n";
    }
  }

  insertionSort(A, n);

  return 0;
}
