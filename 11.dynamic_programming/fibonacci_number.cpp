#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

void initializeMemory(int Memory[]) {
  Memory[0] = 1;
  Memory[1] = 1;
}

void calculate(int Memory[], int i) {
  if (i == 0 || i == 1) return;
  Memory[i] = Memory[i - 1] + Memory[i - 2];
}

int main() {
  int n;
  cin >> n;
  int Memory[n + 1];

  initializeMemory(Memory);
  
  rep(i, n + 1) {
    calculate(Memory, i);
  }

  cout << Memory[n] << endl;
}
