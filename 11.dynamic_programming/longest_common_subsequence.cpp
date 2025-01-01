#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<string>
#include<algorithm>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

static const int N = 1000;

int lcs(string X, string Y) {
  int C[N + 1][N + 1];
  int m = X.size();
  int n = Y.size();
  int maxl = 0;

  X = ' ' + X;
  Y = ' ' + Y;

  rep(i, m + 1) C[i][0] = 0;
  rep(j, n + 1) C[0][j] = 0;

  for (int i = 1; i < m + 1; i++) {
    for (int j = 1; j < n + 1; j++) {
      if (X[i] == Y[j]) {
        C[i][j] = C[i - 1][j - 1] + 1; 
      }
      else {
        C[i][j] = max(C[i - 1][j], C[i][j - 1]);
      }
      maxl = max(maxl, C[i][j]);
    }
  }

  return maxl;
}

int main() {
  int n;
  cin >> n;
  string s1, s2;
  rep(i, n) {
    cin >> s1 >> s2;
    cout << lcs(s1, s2) << endl;
  }

  return 0;
}
