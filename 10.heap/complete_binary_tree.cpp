#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int main() {
  int n;
  cin >> n;
  int Heap[n + 1];
  for (int i = 1; i < n + 1; i++) cin >> Heap[i];

  for (int i = 1; i < n + 1; i ++) {
    cout << "node " << i << ": key = " << Heap[i] << ", ";
    if (i / 2 >= 1) cout << "parent key = " << Heap[i / 2] << ", ";
    if (2 * i <= n) cout << "left key = " << Heap[2 * i] << ", ";
    if (2 * i + 1 <= n) cout << "right key = " << Heap[2 * i + 1] << ",";
    cout << "\n";
  }

  return 0;
}
