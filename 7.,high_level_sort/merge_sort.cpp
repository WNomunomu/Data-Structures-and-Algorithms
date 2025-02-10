#include <iostream>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

#define INFTY 1000000001

int n;
int count = 0;

void merge(int A[], int left, int mid, int right) {
  int L[mid - left + 1], R[right - mid + 1];

  rep(i, mid - left) L[i] = A[left + i];
  rep(i, right - mid) R[i] = A[mid + i];

  L[mid - left] = INFTY;
  R[right - mid] = INFTY;

  int j = 0;
  int k = 0;

  rep(i, right - left) {
    count++;
    if (R[k] > L[j]) {
      A[left + i] = L[j];
      j++;
    }
    else {
      A[left + i] = R[k];
      k++;
    }
  }

}

void mergeSort(int A[], int left, int right) {
  // 要素数が1になったら分割しない
  if (left + 1 < right) {
    int mid = (right + left) / 2;
    mergeSort(A, left, mid);
    mergeSort(A, mid, right);
    merge(A, left, mid, right);
  }
}

int main() {
  scanf("%d", &n);

  int A[n];

  rep(i, n) scanf("%d", &A[i]);

  mergeSort(A, 0, n);

  // n = 5
  // left = 0, mid = 2, right = 5
  // 0  1  2  3  4
  // 5, 3, 2, 1, 4

  rep(i, n) {
    if (i != 0) printf(" ");
    printf("%d", A[i]);
  }

  printf("\n");
  
  printf("%d\n", count);

  return 0;
}
