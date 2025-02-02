#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

static const int NIL = -1;
static const int MAX = 1000000;

int n;
vector<vector<int>> M;

// 各時点での各 node の最短重さとその場合の親
vector<int> weightOfNode;
vector<int> parentOfNode;
vector<bool> isCheckedNode;

bool areNotAllNodesChecked() {
  rep(i, n) {
    if (isCheckedNode[i] == false) {
      return true;
    }
  }
  return false;
}

void dijkstra() {
  // initialize
  rep(i, n) {
    weightOfNode[i] = MAX;
    parentOfNode[i] = NIL;
    isCheckedNode[i] = false;
  }

  weightOfNode[0] = 0;
  parentOfNode[0] = NIL;

  int u = 0;

  while (true) {
    isCheckedNode[u] = true;
    int v;
    int lightestWeight = MAX;
    rep(i, n) {
      if (isCheckedNode[i] == false) {
        if (weightOfNode[i] > M[u][i] + weightOfNode[u]) {
          weightOfNode[i] = M[u][i] + weightOfNode[u];
          parentOfNode[i] = u;
        }
        if (lightestWeight > weightOfNode[i]) {
          lightestWeight = weightOfNode[i];
          v = i;
        }
      }
    }

    if (lightestWeight == MAX) break;

    u = v;
  }
}

int main() {
  cin >> n;

  M.resize(n, vector<int>(n));
  weightOfNode.resize(n);
  parentOfNode.resize(n);
  isCheckedNode.resize(n);

  int u, k, v, c;

  rep(i, n) {
    rep(j, n) {
      M[i][j] = MAX;
    }
  }

  rep(i, n) {
    cin >> u >> k;
    rep (i, k) {
      cin >> v >> c;
      M[u][v] = c;
    }
  }

  dijkstra();

  rep(i, n) {
    cout << i << ' ' << weightOfNode[i] << endl;
  }

  return 0;
}
