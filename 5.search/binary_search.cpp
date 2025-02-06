#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int n;
int count = 0;

void binarySearch(int S[], int x) {
  int length = n;
  int left = 0;
  int right = n;
  int mid;

  while (left < right) {
    int mid = (right + left) / 2;
    if (x == S[mid]) {
      count++;
      return;
    }
    else if (x > S[mid]) {
      left = mid + 1;
    }
    else {
      right = mid;
    }
  }
};

int main() {
  int q;
  cin >> n;
  int S[n];
  rep(i, n) cin >> S[i];
  cin >> q;
  int t;
  rep(i, q) {
    cin >> t;
    binarySearch(S, t);
  }

  cout << count << endl;

  return 0;
}
