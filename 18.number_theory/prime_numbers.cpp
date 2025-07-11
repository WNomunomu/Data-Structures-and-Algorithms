#include <iostream>
#include <vector>

using namespace std;

// 愚直な実装
// bool isPrimeNumber(int n) {
//   if (n <= 1) {
//     return false;
//   }

//   for (int i = 2; i < n; i++) {
//     if (n % i == 0) {
//       return false;
//     }
//   }

//   return true;
// }

bool isPrimeNumber(int n) {
  if (n <= 1) {
    return false;
  }
  else if (n == 2) {
    return true;
  }
  else if (n % 2 == 0) {
    return false;
  }
  else {
    for (int i = 3; i * i <= n; i += 2) {
      if (n % i == 0) {
        return false;
      }
    }
    return true;
  }
}

int main(void) {
  int n;
  cin >> n;

  int primeNumberCount = 0;

  for (int i = 0; i < n; i++) {
    int number;
    cin >> number;
    if (isPrimeNumber(number)) {
      primeNumberCount++;
    }
  }

  cout << primeNumberCount << endl;

  return 0;
}
