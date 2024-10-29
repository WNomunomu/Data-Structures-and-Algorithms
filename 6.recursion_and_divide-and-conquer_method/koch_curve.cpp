#include<stdio.h>
#include<math.h>
using namespace std;

struct Point { double x, y; };

void draw(int n, Point p1, Point p2) {
  if (n == 0) return;
  
  double theta = M_PI * 60.0 / 180.0;

  Point s, t, u;
  s.x = (p2.x + p1.x * 2) / 3;
  s.y = (p2.y + p1.y * 2) / 3;
  t.x = (p2.x * 2 + p1.x) / 3;
  t.y = (p2.y * 2 + p1.y) / 3;
  u.x = s.x + (t.x - s.x) * cos(theta) - (t.y - s.y) * sin(theta);
  u.y = s.y + (t.y - s.y) * cos(theta) + (t.x - s.x) * sin(theta);

  draw(n - 1, p1, s);
  printf("%.8f %.8f\n", s.x, s.y);
  draw(n - 1, s, u);
  printf("%.8f %.8f\n", u.x, u.y);
  draw(n - 1, u, t);
  printf("%.8f %.8f\n", t.x, t.y);
  draw(n - 1, t, p2);
}

int main() {
  int n;
  scanf("%d", &n);

  Point p1, p2;
  p1.x = 0;
  p1.y = 0;
  p2.x = 100;
  p2.y = 0;

  printf("%.8f %.8f\n", p1.x, p1.y);
  draw(n, p1, p2);
  printf("%.8f %.8f\n", p2.x, p2.y);
}