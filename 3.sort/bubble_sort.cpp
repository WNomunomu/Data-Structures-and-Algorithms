#include<iostream>
using namespace std;

#define MAX 100005
#define NIL -1
#define rep(i, n) for (int i = 0; (i) < (n); ++(i))

int swapCount = 0;

void bubbleSort(int A[], int n) {
  int flag = 1;
  int unSortedFirst = 0;
  while (flag) {
    flag = 0;
    for (int j = n - 1; j > unSortedFirst; j--) {
      if (A[j] < A[j - 1]) {
        swap(A[j], A[j - 1]);
        swapCount++;
        flag = 1;
      }
    }
    unSortedFirst++;
  }
}

int main() {
  int n;
  cin >> n;
  int A[n];
  rep(i, n) cin >> A[i];
  
  bubbleSort(A, n);

  rep(i, n) {
    if (i != n - 1) cout << A[i] << " ";
    else cout << A[i] << "\n";
  }

  cout << swapCount << "\n";

  return 0;
}
