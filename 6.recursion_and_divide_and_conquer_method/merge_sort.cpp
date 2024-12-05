#include <stdio.h>

#define INFTY 1000000001;
int count = 0;

void merge(int S[], int left, int mid, int right)
{
  int n1 = mid - left;
  int n2 = right - mid;
  int L[n1 + 1], R[n2 + 1];

  for (int i = 0; i < n1; i++)
    L[i] = S[left + i];
  for (int i = 0; i < n2; i++)
    R[i] = S[mid + i];

  L[n1] = INFTY;
  R[n2] = INFTY;

  int j = 0, k = 0;

  for (int i = left; i < right; i++) {
    count++;
    if (R[j] >= L[k]) {
      S[i] = L[k];
      k++;
    }
    else {
      S[i] = R[j];
      j++;
    }
  }
}

void merge_sort(int S[], int left, int right) {
  // 要素数が1になったら分割しない
  if (left + 1 < right) {
    int mid = (left + right) / 2;
    merge_sort(S, left, mid);
    merge_sort(S, mid, right);

    // 最後のマージ
    merge(S, left, mid, right);
  }
}

int main()
{
  int n;
  scanf("%d", &n);
  int S[n];
  for (int i = 0; i < n; i++)
    scanf("%d", &S[i]);

  merge_sort(S, 0, n);

  for (int i = 0; i < n; i++) {
    if (i > 0)
      printf(" ");
    printf("%d", S[i]);
  }

  printf("\n");

  printf("%d\n", count);

}
