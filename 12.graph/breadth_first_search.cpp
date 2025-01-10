#include<iostream>
#include<queue>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

static const int N = 100;
static const int INFTY = (1<<21);

int n, M[N][N];
int distanceArray[N];

void bfs(int s) {
  queue<int> q;
  q.push(s);
  rep(i, n) {
    distanceArray[i] = INFTY;
  }
  distanceArray[s] = 0;
  while (!q.empty()) {
    int u = q.front();
    q.pop();
    rep(v, n) {
      if (M[u][v] == 1 && distanceArray[v] == INFTY) {
        distanceArray[v] = distanceArray[u] + 1;
        q.push(v);
      }
      else {
        continue;
      }
    }
  }
  rep(i, n) {
    cout << i + 1 << " " << ((distanceArray[i] == INFTY) ? (-1) : distanceArray[i]) << endl;
  }
}

int main() {
  int u, k, v;

  cin >> n;
  rep(i, n) {
    rep(j, n) M[i][j] = 0;
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

  bfs(0);

  return 0;
}
