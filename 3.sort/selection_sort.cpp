#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int n;
vector<int> A;
int swapCount = 0;

void selectionSort() {
  int notSortedHead = 0;

  rep(i, n) {
    int minIndex = notSortedHead;
    for (int i = notSortedHead; i < n; i++) {
      if (A[minIndex] > A[i]) minIndex = i;
    }
    if (A[notSortedHead] > A[minIndex]) {
      swap(A[notSortedHead], A[minIndex]);
      swapCount++;
    }
    notSortedHead++;
  }
}

int main() {
  cin >> n;
  A.resize(n);
  rep(i, n) {
    cin >> A[i];
  }

  selectionSort();

  rep(i, n) {
    if (i != 0) cout << ' ';
    cout << A[i];
  }
  cout << endl;
  cout << swapCount << endl;

  return 0;
}
