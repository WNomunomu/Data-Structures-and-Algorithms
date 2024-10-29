#include<stdio.h>
using namespace std;

int A[50], n;

bool solve(int i, int m) {
  if (i > n) return false;
  if (m == 0) return true;
  bool res = solve(i+1, m) || solve(i+1, m-A[i]);
  return res;
}

int main() {
  int q;
  scanf("%d", &n);
  for (int i=0; i<n; i++) scanf("%d", &A[i]);
  scanf("%d", &q);
  int m[q];
  for (int i=0; i<q; i++) scanf("%d", &m[i]);

  for (int i=0; i<q; i++) {
    if (solve(0, m[i])) {
      printf("yes\n");
    }
    else {
      printf("no\n");
    }
  }
}