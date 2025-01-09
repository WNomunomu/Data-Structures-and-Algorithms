#include<iostream>
#include<stack>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

static const int N = 100;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
static const int NIL = -1;

int n, M[N][N];
int color[N], d[N], f[N], tt;
// 各ノードの隣を何番目まで調べたか。
// ex: nt[0] = 1 だったら 0 番ノードの隣について既に 1 までは調べたことになる。
int nt[N];

int next(int u) {
  for (int v = nt[u]; v < n; v++) {
    nt[u] = v + 1;
    if (M[u][v]) return v;
  }
  return NIL;
}

void dfs_visit(int r) {
  rep(i, n) nt[i] = 0;

  stack<int> S;
  S.push(r);
  color[r] = GRAY;
  d[r] = ++tt;

  while (!S.empty()) {
    int u = S.top();
    int v = next(u);
    // 隣が存在するなら探索
    if (v != -1) {
      if (color[v] == WHITE) {
        color[v] = GRAY;
        d[v] = ++tt;
        S.push(v);
      }
    }
    // 隣が存在しなければ戻って探索終了
    else {
      S.pop();
      color[u] = BLACK;
      f[u] = ++tt;
    }
  }
}

void dfs() {
  // initialize
  rep(i, n) {
    color[i] = WHITE;
    nt[i] = 0;
  }
  tt = 0;

  // 未訪問の u を始点として深さ優先探索
  rep(u, n) {
    if (color[u] == WHITE) dfs_visit(u);
  }
  rep(i, n) {
    cout << i + 1 << " " << d[i] << " " << f[i] << endl;
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
    rep(i, k) {
      cin >> v;
      v--;
      M[u][v] = 1;
    }
  }

  dfs();

  return 0;
}
