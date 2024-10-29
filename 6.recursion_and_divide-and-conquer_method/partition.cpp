#include<stdio.h>

int partition(int A[], int n, int d) {
  int index = 0;

  for (int i = 0; i < n - 1; i++) {
    if (A[i] <= d) {
      int x = A[index];
      A[index] = A[i];
      A[i] = x;
      index++;
    }
  }

  A[n - 1] = A[index];
  A[index] = d;

  return index;
}

int main() {
  int n;
  scanf("%d", &n);
  int A[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &A[i]);

  int d = A[n - 1];

  int index = partition(A, n, d);

  for (int i = 0; i < n; i++) {
    if (i > 0) {
      printf(" ");
    }
    if (i == index) {
      printf("[%d]", A[i]);
    }
    else {
      printf("%d", A[i]);
    }
  }
  printf("\n");
}
