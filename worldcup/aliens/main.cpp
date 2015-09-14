#include <bits/stdc++.h>
using namespace std;

const int SIZE = 1000 + 11;

int n;
int m;
string t[SIZE];

bool input() {
  if (cin >> n >> m && n && m) {
    for (int i = 0; i < n; ++i) cin >> t[i];
    return true;
  }
  return false;
}

int f[SIZE][SIZE]; // foot-prints
int d1[SIZE][SIZE];
int s1[SIZE][SIZE]; 
int d2[SIZE][SIZE];
int s2[SIZE][SIZE];
int d3[SIZE][SIZE];
int s3[SIZE][SIZE];
int d4[SIZE][SIZE];
int s4[SIZE][SIZE];

void print(int t[SIZE][SIZE]) {
  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      cout << t[i][j] << ", ";
    }
    cout << endl;
  }
  cout << endl;
}

inline bool inner(int r, int c) {
  return r >= n || r < 0 || c >= m || c < 0;
}

inline bool valid(int r, int c) {
  return inner(r, c) && f[r][c];
}

int find_max(int r, int c) {
  return max(max(s1[r][c], s2[r][c]), max(s3[r][c], s4[r][c]));
}

int find_max_min() {
  int res = max(n, m);
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      if (f[i][j])
        res = min(res, find_max(i, j));
  return res;
}

int solve() {
  // convert
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < m; ++j)
      f[i][j] = t[i][j] == '#';

  for (int i = 0; i < n; ++i) {
    for (int j = 0; j < m; ++j) {
      d1[i][j] = s1[i][j] = 0;
      d2[i][j] = s2[i][j] = 0;
      d3[i][j] = s3[i][j] = 0;
      d4[i][j] = s4[i][j] = 0;
    }
  }

  // .#
  // ##
  for (int i = n - 1; i >= 0; --i) {
    d1[i][0] = f[i][0];
    if (i + 1 >= n) continue;
    for (int j = m - 1; j >= 0; --j)
      if (j - 1 >= 0 && f[i][j])
        d1[i][j] = d1[i + 1][j - 1] + 1;
  }
  for (int i = 0; i < m; ++i)
    s1[n - 1][i] = f[n - 1][i];
  for (int i = n - 2;  i >= 0; --i)
    for (int j = 0; j < m; ++j)
      s1[i][j] = min(s1[i + 1][j] + 1, d1[i][j]);

  // #.
  // ##
  for (int i = n - 1; i >= 0; --i) {
    d2[i][m - 1] = f[i][m - 1];
    if (i + 1 >= n) continue;
    for (int j = m - 1; j >= 0; --j)
      if (j + 1 < m && f[i][j])
        d2[i][j] = d2[i + 1][j + 1] + 1;
  }
  for (int i = 0; i < m; ++i)
    s2[n - 1][i] = f[n - 1][i];
  for (int i = n - 2; i >= 0; --i)
    for (int j = 0; j < m; ++j)
      s2[i][j] = min(s2[i + 1][j] + 1, d2[i][j]);

  // ##
  // .#

  // ##
  // #.

  cout << "### HEADER ###" << endl;

  cout << "d1" << endl;
  print(d1);
  cout << "s1" << endl;
  print(s1);

  // TODO: cout << "d2" << endl;
  // print(d2);
  // cout << "s2" << endl;
  // print(s2);

  return find_max_min();
}

int main() {
  while (input()) {
    cout << "res: " << solve() << endl;
  }
  return 0;
}
