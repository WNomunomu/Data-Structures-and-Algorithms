#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

static const int MAX = 10000;

int S[MAX];
int top = 0;

int pop() {
  top--;
  return S[top + 1];
};

void push(int x) {
  top++;
  S[top] = x;
};

int main() {
  string operation;
  while(cin >> operation) {
    int a, b;
    if (operation == "+") {
      a = pop();
      b = pop();
      push(a + b);
    }
    else if (operation == "-") {
      a = pop();
      b = pop();
      push(b - a);
    }
    else if (operation == "*") {
      a = pop();
      b = pop();
      push(a * b);
    }
    else {
      push(stoi(operation));
    }
  }

  int answer = pop();

  cout << answer << endl;

  return 0;
}
