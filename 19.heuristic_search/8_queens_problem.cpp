#include <cassert>
#include <iostream>
#include <vector>
using namespace std;

static const int BOARD_SIZE = 8;
static const int AVAILABLE = -1;  // 空いている
static const int OCCUPIED = 1;    // 占有されている
static const char QUEEN_SYMBOL = 'Q';
static const char EMPTY_SYMBOL = '.';

bool isPrinted = false;

// 解答を表示する関数
void printSolution(vector<vector<bool>>& fixedQueens, vector<int>& rowUsed,
                   vector<int>& columnUsed) {
  cout << "printSolution" << endl;
  // 固定されたクイーンの位置と解答が一致するかチェック
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      if (fixedQueens[row][col]) {
        if (rowUsed[row] != col) {
          return;  // 固定されたクイーンと位置が合わない場合は表示しない
        }
      }
    }
  }

  // 解答を表示
  for (int row = 0; row < BOARD_SIZE; row++) {
    for (int col = 0; col < BOARD_SIZE; col++) {
      cout << ((rowUsed[row] == col) ? QUEEN_SYMBOL : EMPTY_SYMBOL);
    }
    cout << endl;
    isPrinted = true;
  }
}

// バックトラッキングで解を探索する再帰関数
void solveNQueens(
    int currentRow,
    vector<vector<bool>>& fixedQueens,  // 固定されたクイーンの位置
    vector<int>& rowUsed,               // 各行のクイーンの列位置
    vector<int>& columnUsed,            // 各列が使用済みかどうか
    vector<int>& diagonalPos,           // 正の対角線が使用済みかどうか
    vector<int>& diagonalNeg) {         // 負の対角線が使用済みかどうか

  if (isPrinted) {
    return;
  }

  // 全ての行にクイーンを配置できたら解答を出力
  if (currentRow == BOARD_SIZE) {
    printSolution(fixedQueens, rowUsed, columnUsed);
    return;
  }

  // 現在の行の各列を試す
  for (int col = 0; col < BOARD_SIZE; col++) {
    // この位置にクイーンを置けるかチェック
    // 1. 列が使用済みでない
    // 2. 正の対角線（row+col）が使用済みでない
    // 3. 負の対角線（row-col+7）が使用済みでない
    if (columnUsed[col] == OCCUPIED ||
        diagonalPos[currentRow + col] == OCCUPIED ||
        diagonalNeg[currentRow - col + BOARD_SIZE - 1] == OCCUPIED) {
      continue;  // この位置には置けない
    }

    // クイーンを配置
    rowUsed[currentRow] = col;
    columnUsed[col] = OCCUPIED;
    diagonalPos[currentRow + col] = OCCUPIED;
    diagonalNeg[currentRow - col + BOARD_SIZE - 1] = OCCUPIED;

    // 次の行を処理
    solveNQueens(currentRow + 1, fixedQueens, rowUsed, columnUsed, diagonalPos,
                 diagonalNeg);

    // バックトラッキング（元の状態に戻す）
    rowUsed[currentRow] = AVAILABLE;
    columnUsed[col] = AVAILABLE;
    diagonalPos[currentRow + col] = AVAILABLE;
    diagonalNeg[currentRow - col + BOARD_SIZE - 1] = AVAILABLE;
  }
}

int main() {
  // 固定されたクイーンの位置を記録する配列
  vector<vector<bool>> fixedQueens(BOARD_SIZE, vector<bool>(BOARD_SIZE, false));

  // 各行のクイーンの列位置を記録する配列
  vector<int> rowUsed(BOARD_SIZE, AVAILABLE);

  // 制約を管理する配列
  vector<int> columnUsed(BOARD_SIZE, AVAILABLE);  // 各列の使用状況
  vector<int> diagonalPos(2 * BOARD_SIZE - 1,
                          AVAILABLE);  // 正の対角線の使用状況
  vector<int> diagonalNeg(2 * BOARD_SIZE - 1,
                          AVAILABLE);  // 負の対角線の使用状況

  int numFixedQueens;
  cin >> numFixedQueens;

  // 固定されたクイーンの位置を入力
  for (int i = 0; i < numFixedQueens; i++) {
    int row, col;
    cin >> row >> col;
    fixedQueens[row][col] = true;
  }

  // 解探索を開始
  solveNQueens(0, fixedQueens, rowUsed, columnUsed, diagonalPos, diagonalNeg);

  return 0;
}
