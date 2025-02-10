#include<iostream>

using namespace std;

#define MAX 100000
#define SENTIMENTAL 2000000000
#define rep(i, n) for (int i = 0; i < n; i++)

struct Card {
  char suit;
  int value;
};

void merge(Card A[], int start, int end, int mid) {
  int n1 = mid - start;
  int n2 = end - mid;
  Card L[n1 + 1], R[n2 + 1];

  rep(i, n1) {
    L[i] = A[start + i];
  }
  rep(i, n2) {
    R[i] = A[mid + i];
  }

  L[n1] = R[n2] = { 'n', SENTIMENTAL };

  int j = 0;
  int k = 0;
  rep(i, end - start) {
    if (R[j].value < L[k].value) {
      A[start + i] = R[j];
      j++;
    }
    else {
      A[start + i] = L[k];
      k++;
    }
  }
}

void mergeSort(Card A[], int start, int end) {
  int mid = (start + end) / 2;
  if (start + 1 < end) {
    mergeSort(A, start, mid);
    mergeSort(A, mid, end);
    merge(A, start, end, mid);
  }
}

int partition(Card A[], int start, int end) {
  int x = A[end].value;
  int smallerThanX = start - 1;

  // rep(i, end - start) {
  //   if (A[start + i].value <= x) {
  //     swap(A[smallerThanX + 1], A[i]);
  //     smallerThanX++;
  //   }
  // }

  for (int j = start; j < end; j++) {
    if (A[j].value <= x) {
      smallerThanX++;
      swap(A[smallerThanX], A[j]);
    }
  }


  swap(A[smallerThanX + 1], A[end]);

  return smallerThanX + 1;
}

void quickSort(Card A[], int start, int end) {
  if (start < end) {
    int index = partition(A, start, end);
    quickSort(A, start, index - 1);
    quickSort(A, index + 1, end);
  }
}

int main() {
  int n, value;
  struct Card A[MAX], B[MAX];
  char S[10];

  scanf("%d", &n);

  rep(i, n) {
    scanf("%s %d", S, &value);
    A[i].suit = B[i].suit = S[0];
    A[i].value = B[i].value = value;
  }

  mergeSort(A, 0, n);
  quickSort(B, 0, n - 1);

  bool isStable = true;

  rep(i, n) {
    if (A[i].suit != B[i].suit) isStable = false;
  }

  if (isStable) {
    printf("Stable\n");
  }
  else {
    printf("Not stable\n");
  }

  rep(i, n) {
    printf("%c %d\n", B[i].suit, B[i].value);
  }

  return 0;
}
