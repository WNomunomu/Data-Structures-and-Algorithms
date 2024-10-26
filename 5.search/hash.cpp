#include<stdio.h>
#include<string.h>

#define M 1046527
#define L 14

int n;
char H[M][L];

int getChar(char ch) {
  if (ch == 'A') return 1;
  else if (ch == 'C') return 2;
  else if (ch == 'G') return 3;
  else if (ch == 'T') return 4;
  else return 0;
}

int getKey(char str[]) {
  int sum = 0, p = 1;
  for (int i=0; i<strlen(str); i++) {
    sum += p*getChar(str[i]);
    p *= 5;
  }
  return sum;
}

int h1(int key) { return key % M; }
int h2(int key) { return 1 + (key % (M - 1)); }

int insert(char str[]) {
  int hashKey;
  int key = getKey(str);

  for (int i=0; ; i++) {
    hashKey = (h1(key) + i*h2(key)) % M;

    if (strlen(H[hashKey]) == 0) {
      strcpy(H[hashKey], str);
      return 0;
    }
  }

  return 0;
}

int find(char str[]) {
  int hashKey;
  int key = getKey(str);

  for (int i=0; ; i++) {
    hashKey = (h1(key) + i*h2(key)) % M;

    // if (H[hashKey] == str)
    // これだと H[hashKey] の文字列と str が同じアドレスを指しているかを判定してしまう。
    if (strcmp(H[hashKey], str) == 0) {
      return 1;
    }
    // これ以上探す範囲がなくなったら終了
    else if (strlen(H[hashKey]) == 0) return 0;
  }

  return 0;
}

int main() {
  int i, n, h;
  char str[14], com[9];
  
  for (i = 0; i < M; i++) H[i][0] = '\0';

  scanf("%d", &n);

  for (i = 0; i < n; i++) {
    scanf("%s %s", com, str);

    if (com[0] == 'i') {
      insert(str);
    }
    else {
      if (find(str)) {
        printf("yes\n");
      }
      else {
        printf("no\n");
      }
    }
  }
  return 0;
}
