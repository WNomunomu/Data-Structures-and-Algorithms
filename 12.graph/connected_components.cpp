#include<iostream>
#include<stack>
#include<vector>
using namespace std;

#define rep(i, n) for(int i = 0; i < n; i++)

static const int MAX = 100000;
static const int NIL = -1;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;

int n;
vector<int> G[MAX];
int color[MAX];

void dfs(int r, int c) {
  stack<int> S;
  S.push(r);
  color[r] = c;
  while (!S.empty()) {
    int u = S.top(); S.pop();
    // 隣接要素に同じ色を設定する
    rep(i, G[u].size()) {
      int v = G[u][i];
      if (color[v] == NIL) {
        color[v] = c;
        S.push(v);
      }
    }
  }
}

void assignColor() {
  int id = 1;
  rep(i, n) color[i] = NIL;
  rep(u, n) {
    if (color[u] == NIL) dfs(u, id++);
  }
}

int main() {
  int s, t, m, q;

  cin >> n >> m;

  rep(i, m) {
    cin >> s >> t;
    G[s].push_back(t);
    G[t].push_back(s);
  }

  assignColor();

  cin >> q;

  rep(i, q) {
    cin >> s >> t;
    if (color[s] == color[t]) {
      cout << "yes" << endl;
    }
    else {
      cout << "no" << endl;
    }
  }

  return 0;
}
