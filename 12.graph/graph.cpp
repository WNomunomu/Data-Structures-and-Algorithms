#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++) 

#define N 100

int main() {
  int M[N][N];
  int n, u, v, k;
  cin >> n;

  rep(i, n) {
    rep(j, n) {
      M[i][j] = 0;
    }
  }

  rep(i, n) {
    cin >> u >> k;
    u--;
    rep(j, k) {
      cin >> v;
      v--;
      M[u][v] = 1;
    }
  }

  rep(i, n) {
    rep(j, n) {
      if (j != 0) {
        cout << ' ';
      }
      cout << M[i][j];
    }
    cout << endl;
  }

  return 0;
}
