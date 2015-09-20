#include <bits/stdc++.h>
using namespace std;

typedef long long Int;

const int SIZE = 36;

Int n;
Int a[SIZE];

bool input() {
  if (cin >> n) {
    for (int i = 0; i < n; ++i) cin >> a[i];
    return true;
  }
  return false;
}

Int sum[SIZE][SIZE];
Int rec(int i, Int x) {
  if (i >= n) return x == 0;
  Int res = 0;
  for (int j = i; j < n; ++j) {
    res += rec(j + 1, x ^ sum[i][j]);
  }
  return res;
}

void init_sum() {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < n; ++j) {
      sum[i][j] = 0;
    }
  }
  for (int i = 0; i < n; ++i) {
    for (int j = i; j < n; ++j) {
      for (int k = i; k <= j; ++k)  {
        sum[i][j] += a[k];
      }
    }
  }
}

int solve() {
  init_sum();
  return rec(0, 0);
}

int main() {
  while (input()) {
    cout << solve() << endl;
  }
  return 0;
}
