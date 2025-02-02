#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

static const int NIL = -1;
static const int WHITE = 0;
static const int GRAY = 1;
static const int BLACK = 2;
static const int INFTY = (1 << 21);

int n;
vector<vector<int>> M;
vector<int> color;
vector<int> d;
vector<int> p;

void initialize() {
  rep(i, n) {
    color[i] = WHITE;
    d[i] = INFTY;
  }
}

void registerMinCost(int u, int v) {
  d[v] = M[u][v];
  p[v] = u;
}

void prim() {
  initialize();

  int u;

  d[0] = 0;
  p[0] = NIL;

  while (true) {
    int minCost = INFTY;
    // このループで移動先の頂点を確定する
    rep(i, n) {
      if (color[i] != BLACK && d[i] < minCost) {
        minCost = d[i];
        u = i;
      }
    }

    // 全ての頂点を探索し終わった場合
    if (minCost == INFTY) break;

    color[u] = BLACK;

    // 見ている頂点 u に隣接する頂点を見て、これまで登録したその頂点までのコストより小さければ、最小コストとして登録
    // 次に見る点の候補を登録
    // 次のループで登録した中から最小のものが確定する辺として扱われる
    rep(v, n) {
      if (color[v] != BLACK && M[u][v] != NIL) {
        // 従来の d[v] より小さいものが見つかれば登録
        if (M[u][v] < d[v]) {
          registerMinCost(u, v);
          color[v] = GRAY;
        }
      }
    }
  }
};

void printWeightSum() {
  int sum = 0;
  rep(i, n) {
    if (p[i] != NIL) { // 親が存在しない場合をスキップ
      sum += M[i][p[i]];
    }
  }
  cout << sum << endl;
};

int main() {
  cin >> n;

  M.resize(n, vector<int>(n));
  color.resize(n);
  d.resize(n);
  p.resize(n);

  rep(i, n) {
    rep(j, n) {
      cin >> M[i][j];
    }
  }

  prim();

  printWeightSum();

  return 0;
}
