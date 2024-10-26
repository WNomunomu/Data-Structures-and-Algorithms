#include<stdio.h>

bool linearSearch(int t, int S[], int n) {
  for (int i=0; i<n; i++) {
    if (S[i] == t) {
      return true;
    }
  }
  return false;
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
    if (linearSearch(T[i], S, n)) {
      sum++;
    }
  }

  printf("%d\n", sum);
}
