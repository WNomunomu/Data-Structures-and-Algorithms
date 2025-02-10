#include<vector>
#include<iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int n;
vector<int> A;

int largerThanX = -1, smallerThanX = -1;

void partition(int x) {
  rep(i, n - 1) {
    if (A[i] <= x) {
      swap(A[smallerThanX + 1], A[i]);
      largerThanX++;
      smallerThanX++;
    }
    else {
      largerThanX++;
    }
  }

  swap(A[smallerThanX + 1], A[n - 1]);
}

int main() {
  scanf("%d", &n);

  A.resize(n);

  rep(i, n) scanf("%d", &A[i]);

  int x = A[n - 1];

  partition(x);

  rep(i, n) {
    if (i != 0) printf(" ");
    if (i == smallerThanX + 1) {
      printf("[%d]", A[i]);
    }
    else {
      printf("%d", A[i]);
    }
  }
  printf("\n");

  return 0;
}
