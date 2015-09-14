#include <iostream>
#include <algorithm>
using namespace std;

int main() {
  int n = 10;
  int A[n];
  for (int i = 0; i < n; ++ i) {
    cin >> A[i];
  }
  sort(A, A + n, greater<int>());
  int res = A[0] + A[2] + A[4];
  cout << res << endl;
  return 0;
}
