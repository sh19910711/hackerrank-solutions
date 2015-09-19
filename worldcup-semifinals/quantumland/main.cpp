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

double calc(int i, int root, double e = 1.0) {
  int next = w[i];
  if (next == root) return e * p[i];
  return calc(next, root, e * p[i]);
}

int v[SIZE];
double rec(int i, int root) {
  v[i] = root;
  int next = w[i];
  if (v[next] != -1 && v[next] != root) return 0;
  if (v[next] == root) {
    if (next == w[next]) return 0.0;
    return calc(next, next);
  }
  return rec(next, root);
}

double solve() {
  double res = 0;
  fill(v, v + SIZE, -1);

  for (int i = 0; i < n; ++i) {
    if (v[i] == -1) res += rec(i, i);
  }

  return res;
}

int main() {
  while (input()) {
    printf("%.2f\n", solve());
  }
  return 0;
}

