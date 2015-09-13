#include <bits/stdc++.h>
using namespace std;

typedef long long Int;

const int SIZE = 10;

int n;
int m;
string t[SIZE];
Int o[SIZE]; // o[k] := obstacles in k-th row

bool input() {
  if (cin >> n >> m) {
    for (int i = 0; i < n; ++i) cin >> t[i];
    return true;
  }
  return false;
}

inline Int bit0(Int r, Int c) {
  return 1LL << Int(r + c);
}

inline Int bit1(Int r, Int c) {
  return 1LL << Int(r - c + 3 * m);
}

inline Int bitf() {
  return (1LL << (5LL * m)) - 1LL;
}

void find_obstacles() {
  for (int i = 0; i < n; ++i) {
    o[i] = bitf();
    for (int j = 0; j < m; ++j) {
      if (t[i][j] == '*')
        o[i] &= bitf() ^ bit0(i, j) ^ bit1(i, j);
    }
    // cout << i << ": " << o[i] << endl;
  }
}

bool impossible() {
  return count(t, t + SIZE, string(m, '*')) > 0;
}

int res;
void rec(int k, Int s) {
  if (k >= n) {
    ++res;
    return;
  }

  s &= o[k];
  for (int i = 0; i < m; ++i) {
    if (t[k][i] == '*') continue;
    if (!(s & (bit0(k, i) | bit1(k, i))))
      rec(k + 1, s | bit0(k, i) | bit1(k, i));
  }
}

Int solve() {
  if (impossible()) return 0;
  find_obstacles();
  res = 0;
  rec(0, 0);
  return res;
}

int main() {
  while (input()) {
    cout << solve() << endl;
  }
  return 0;
}
