#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int n;
vector<int> A;

bool isCreatableNumber(int x, int i = 0) {
  if (x == 0) return true;
  if (i == n) return false;
  return isCreatableNumber(x, i + 1) || isCreatableNumber(x - A[i], i + 1);
}

int main() {
  cin >> n;
  A.resize(n);
  rep(i, n) cin >> A[i];
  int q, m;
  cin >> q;
  rep(i, q) {
    cin >> m;
    if (isCreatableNumber(m)) cout << "yes" << endl;
    else cout << "no" << endl;
  }

  return 0;
}
