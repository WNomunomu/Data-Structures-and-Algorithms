#include <iostream>
#include <math.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < n; i++)

int n;
double theta = M_PI * 60 / 180;

struct Vector {
  double x;
  double y;
};

void koch_curve(Vector p1, Vector p2, int count) {
  if (count == 0) return;

  Vector s = { x: (p2.x + p1.x * 2) / 3, y: (p2.y + p1.y * 2) / 3 };
  Vector t = { x: (p2.x * 2 + p1.x) / 3, y: (p2.y * 2 + p1.y) / 3 };
  Vector u = {
    x: s.x + cos(theta) * (t.x - s.x) - sin(theta) * (t.y - s.y),
    y: s.y + sin(theta) * (t.x - s.x) + cos(theta) * (t.y - s.y),
  };

  koch_curve(p1, s, count - 1);
  printf("%.8f %.8f\n", s.x, s.y);
  koch_curve(s, u, count - 1);
  printf("%.8f %.8f\n", u.x, u.y);
  koch_curve(u, t, count - 1);
  printf("%.8f %.8f\n", t.x, t.y);
  koch_curve(t, p2, count - 1);
}

int main() {
  scanf("%d", &n);
  Vector p1 = { x: 0, y: 0 };
  Vector p2 = { x: 100, y: 0 };

  printf("%.8f %.8f\n", p1.x, p1.y);
  koch_curve(p1, p2, n);
  printf("%.8f %.8f\n", p2.x, p2.y);

  return 0;
}
