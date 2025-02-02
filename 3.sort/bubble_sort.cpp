#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int n;
vector<int> A;
int swapCount = 0;

void bubbleSort() {

  bool flag = true;

  while(flag) {
    flag = false;
    for (int i = n - 1; i >= 0; i--) {
      if (A[i - 1] > A[i]) {
        swap(A[i - 1], A[i]);
        flag = true;
        swapCount++;
      }
    }
  }  

}

int main() {
  cin >> n;
  A.resize(n);
  rep(i, n) cin >> A[i];

  bubbleSort();

  rep(i, n) {
    if (i != 0) cout << ' ';
    cout << A[i];
  }

  cout << endl;

  cout << swapCount << endl;

  return 0;
}
