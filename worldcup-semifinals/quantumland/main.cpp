#include <bits/stdc++.h>
using namespace std;

const int SIZE = 100000 + 11;

int n;
int w[SIZE];
double p[SIZE];

bool input() {
  if (cin >> n) {
    for (int i = 0; i < n; ++i) {
      cin >> w[i] >> p[i];
      --w[i];
      p[i] /= 100.0;
    }
    return true;
  }
  return false;
}

int v[SIZE];
double rec(int cur, double e) {
  // printf("cur = %d, e = %f\n", cur, e);
  if (v[cur]) return e;
  v[cur] = 1;
  int next = w[cur];
  return rec(next, p[cur] * e);
}

double solve() {
  double res = 0;
  fill(v, v + SIZE, 0);
  for (int i = 0; i < n; ++i) {
    if (!v[i]) res += rec(i, 1.0);
  }
  return res;
}

int main() {
  while (input()) {
    printf("%.2f\n", solve());
  }
  return 0;
}

