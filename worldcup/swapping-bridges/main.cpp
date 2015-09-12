#include <bits/stdc++.h>
using namespace std;

typedef set<int> Set;

const int SIZE = 50000 + 11;
const int NONE = -1;

int n;
int y[SIZE];
Set v;

void input() {
  cin >> n;
  for (int i = 0; i < n; ++i) {
    cin >> y[i];
    --y[i];
  }
}

int dfs(int cur) {
  if (v.empty()) return 0;
  v.erase(cur);
  int next = y[cur];
  if (v.count(next)) { // unvisited
    return dfs(next);
  } else { // visited
    if (v.empty()) return 0;
    return dfs(*v.begin()) + 1;
  }
}

int solve() {
  for (int i = 0; i < n; ++i) v.insert(i);
  return dfs(0);
}

int main() {
  int t;
  cin >> t;
  for (int i = 0; i < t; ++i) {
    input();
    cout << solve() << endl;
  }
  return 0;
}
