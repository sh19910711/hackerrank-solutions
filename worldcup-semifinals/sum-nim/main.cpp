#include <bits/stdc++.h>
using namespace std;

const int SIZE = 36;

int n;
int a[SIZE];

bool input() {
  if (cin >> n) {
    for (int i = 0; i < n; ++i) cin >> a[i];
    return true;
  }
  return false;
}

int sum[SIZE][SIZE];
int res;
void rec(int i, int x) {
  if (i >= n) {
    if (x == 0) ++res;
    return;
  }
  for (int j = i; j < n; ++j) {
    rec(j + 1, x ^ sum[i][j]);
  }
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
  res = 0;
  init_sum();

  rec(0, 0);
  return res;
}

int main() {
  while (input()) {
    cout << solve() << endl;
  }
  return 0;
}
