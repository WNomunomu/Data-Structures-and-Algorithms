#include<stdio.h>

// ng と ok の境界線を求めるアルゴリズム
int binarySearch(int key, int S[], int n) {
  int ng = -1;
  int ok = n;

  // 境界線が求まるまで続ける
  while (ok - ng > 1) {
    int mid = (ng + ok) / 2;
    if (S[mid] == key) {
      return 1;
    }
    else if (S[mid] < key) {
      ng = mid;
    }
    else if (S[mid] > key) {
      ok = mid;
    }
  }

  return 0;
}

int main() {
  int n, q;
  int sum = 0;

  scanf("%d", &n);
  int S[n];
  for (int i=0; i<n; i++) scanf("%d", &S[i]);
  scanf("%d", &q);
  int T[q];
  for (int i=0; i<q; i++) scanf("%d", &T[i]);

  for (int i=0; i<q; i++) {
    if (binarySearch(T[i], S, n)) sum++;
  }

  printf("%d\n", sum);
}
