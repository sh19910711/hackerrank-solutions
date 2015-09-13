#include <bits/stdc++.h>
using namespace std;

typedef long long Int;
typedef vector<Int> IntVector;

const int SIZE = 500000 + 11;

int n;
Int a[SIZE];
IntVector g[SIZE];

void init() {
  fill(g, g + SIZE, IntVector());
}

bool input() {
  if (cin >> n) {
    for (int i = 0; i < n; ++i) cin >> a[i];
    for (int i = 0; i < n - 1; ++i) {
      int u, v;
      cin >> u >> v;
      --u;
      --v;
      g[u].push_back(v);
      g[v].push_back(u);
    }
    return true;
  }
  return false;
}

Int res;
Int total;
Int s[SIZE];

void rec(const int cur, const int prev) {
  s[cur] = a[cur];

  long long best = 0;
  for (const auto& next : g[cur]) {
    if (next == prev) continue;
    rec(next, cur);
    s[cur] += s[next];
    best = max(best, s[next]);
  }
  best = max(best, total - s[cur]);

  res = max(res, total - best);
}

Int solve() {
  total = accumulate(a, a + SIZE, Int(0));
  fill(s, s + SIZE, Int(0));
  rec(0, -1);
  return res;
}

int main() {
  while (input()) {
    cout << solve() << endl;
  }
  return 0;
}
