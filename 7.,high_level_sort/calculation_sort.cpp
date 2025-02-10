#include<iostream>

using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

static const int MAX = 2000000;

void calculationSort(int A[], int n) {
  int Count[MAX + 1];
  int Num[n];
  
  rep(i, n) Num[i] = A[i];

  rep(i, MAX + 1) Count[i] = 0;

  rep(i, n) Count[A[i]]++;

  for(int i = 1; i < MAX + 1; i++) Count[i] += Count[i - 1];

  for(int i = n - 1; i >= 0; i--) {
    int num = Num[i];
    int count = Count[num];
    Count[num]--;
    A[count - 1] = num;
  }
}

int main() {
  int n;
  scanf("%d", &n);
  int A[n];
  rep(i, n) scanf("%d", &A[i]);

  calculationSort(A, n);

  rep(i, n) {
    if (i != 0) printf(" ");
    printf("%d", A[i]);
  }
  printf("\n");

  return 0;
}
