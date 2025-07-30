#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void dfs(int startNode, int n, vector<vector<int>> nextNodes, vector<int>& isVisitedNode) {
  stack<int> s;
  s.push(startNode);

  while (!s.empty()) {
    int current = s.top();
    s.pop();

    if (!isVisitedNode[current]) {
      vector<int> nextNodeList = nextNodes[current];

      for (int& nextNode : nextNodeList) {
        if (!isVisitedNode[nextNode]) {
          s.push(nextNode);
        }
      }

      isVisitedNode[current] = true;
      cout << current + 1 << " ";
    }
  }
  cout << endl;
}

int main(void) {
  int n;
  cin >> n;

  vector<vector<int>> nextNodes;
  vector<int> isVisitedNode(n, false);

  for (int i = 0; i < n; i++) {
    int u, k;
    cin >> u >> k;

    u--;

    vector<int> nextNode;

    for (int j = 0; j < k; j++) {
      int v;
      cin >> v;
      v--;
      nextNode.push_back(v);
    }

    nextNodes.push_back(nextNode);
  }

  for (int i = 0; i < n; i++) {
    if (!isVisitedNode[i]) {
      dfs(i, n, nextNodes, isVisitedNode);
    }
  }

  return 0;
}
