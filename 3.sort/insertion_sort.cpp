#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int n;
vector<int> A;

void insertionSort() {
  int sorted = 0;
  rep(i, n) {

    rep(i, n) {
      if (i != 0) cout << ' ';
      cout << A[i];
    }
    cout << endl;
    
    int v = A[sorted + 1];

    for (int j = sorted; j >= 0; j--) {
      if (A[j] > v) {
        A[j + 1] = A[j];
        A[j] = v;
      }
    }

    sorted++;
  }
}

int main() {
  cin >> n;

  A.resize(n);

  rep(i, n) {
    cin >> A[i];
  }

  insertionSort();

  return 0;
}
