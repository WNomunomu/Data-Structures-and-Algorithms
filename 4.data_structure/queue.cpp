#include <iostream>
#include <vector>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

static const int MAX = 100000;

struct Process {
  string name;
  int time;
};

int n;
int head, tail;
Process Queue[MAX];

void initialize() {
  head = 0;
  tail = 0;
}

void enqueue(Process process) {
  Queue[tail] = process;
  tail = (tail + 1) % MAX;
}

Process dequeue() {
  Process process = Queue[head];
  head = (head + 1) % MAX;

  return process;
}

int main() {
  cin >> n;
  int quantum;
  cin >> quantum;

  int sumTime = 0;

  string name;
  int time;
  Process process;

  rep(i, n) {
    cin >> name >> time;
    process = { name, time };
    enqueue(process);
  }

  while(!(head == tail)) {
    process = dequeue();
    time = process.time - quantum;
    if (time <= 0) {
      sumTime += process.time;
      cout << process.name << ' ' << sumTime << endl;
      continue;
    }
    else {
      sumTime += quantum;
      enqueue({ process.name, time });
    }
   
    // もともとこの flag を用いていたが、これを直に while の中に入れることで 0.99 sec 短縮
    // if (head == tail) isQueueEmpty = true;
  }

  return 0;
}
