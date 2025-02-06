#include<stdio.h>
#include<string.h>

#define rep(i, n) for (int i = 0; i < n; i++)

static const int M = 1046527;
static const int L = 14;

char H[M][L];

int convertChar(char ch) {
  if (ch == 'A') return 1;
  else if (ch == 'C') return 2;
  else if (ch == 'G') return 3;
  else if (ch == 'T') return 4;
  else return 0;
}

long long getKey(char str[]) {
  long long sum = 0, p = 1;
  rep(i, strlen(str)) {
    sum += p * (convertChar(str[i]));
    p *= 5;
  }
  return sum;
}

int h1(int key) { return key % M; }
int h2(int key) { return 1 + (key % (M - 1)); }

void insert(char str[]) {
  long long key, h;
  key = getKey(str);
  int i = 0;
  for (i = 0; ; i++) {
    h = (h1(key) + i * h2(key)) % M;
    if (strlen(H[h]) == 0) {
      strcpy(H[h], str);
      return;
    }
  }
}

bool find(char str[]) {
  int h;
  int key = getKey(str);

  for(int i = 0; ; i++) {
    h = (h1(key) + i * h2(key)) % M;

    // if (H[hashKey] == str)
    // これだと H[hashKey] の文字列と str が同じアドレスを指しているかを判定してしまう。
    if (strcmp(H[h], str) == 0) return true;
    // そこから先もすべて 0 つまり、空
    else if (strlen(H[h]) == 0) return false;
  }

  return false;
}

int main() {
  int i, n, h;
  char str[14], operation[9];

  rep(i, M) {
    H[i][0] = '\0';
  }

  scanf("%d", &n);

  rep(i, n) {
    scanf("%s %s", operation, str);

    if (operation[0] == 'i') {
      insert(str);
    }
    else {
      if (find(str)) printf("yes\n");
      else printf("no\n");
    }
  }

  return 0;
}
