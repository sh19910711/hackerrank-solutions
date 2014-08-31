#include <iostream>
using namespace std;

typedef long long Int;

const string YES = "possible";
const string NO = "impossible";

Int R;
Int K;

bool input() {
  return cin >> R >> K;
}

bool solve() {
  Int cnt = 0;
  for ( int i = 2; i * i <= R; ++ i ) {
    if ( R % i == 0 ) {
      if ( i % 4 == 1 ) {
        cnt ++;
      } else if ( i % 4 == 3 ) {
        cnt --;
      }
    }
  }
  if ( R == 1 ) {
    cnt ++;
  } else {
    if ( R % 4 == 1 ) {
      cnt ++;
    } else if ( R % 4 == 3 ) {
      cnt --;
    }
  }
  // cout << R << ", K = " << K << ", cnt = " << cnt << endl;
  return 4 * cnt <= K;
}

int main() {
  int tests;
  cin >> tests;
  for ( int i = 0; i < tests; ++ i ) {
    input();
    cout << ( solve() ? YES : NO ) << endl;
  }
}
