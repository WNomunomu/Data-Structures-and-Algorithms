#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int n;
int count = 0;

void linearSearch(int S[], int x) {
  rep(i, n) {
    if (S[i] == x) {
      count++;
      return;
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
    linearSearch(S, t);
  }

  cout << count << endl;

  return 0;
}
