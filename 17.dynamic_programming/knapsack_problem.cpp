#include <iostream>
#include <vector>

using namespace std;

int main(void) {
  int N, W;
  cin >> N >> W;

  vector<int> prevRow(W + 1, 0);
  vector<int> curRow(W + 1, 0);

  for (int i = 0; i < N; i++) {
    int v, w;
    cin >> v >> w;
    curRow = prevRow;
    for (int j = 1; j < W + 1; j++) {
      if (w <= j) {
        curRow[j] = max(prevRow[j], prevRow[j - w] + v);
      }
    }
    prevRow = curRow;
  }
  
  cout << curRow[W] << endl;

  return 0;
}
