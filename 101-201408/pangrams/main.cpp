#include <iostream>
using namespace std;

string S;

bool input() {
  return getline(cin, S);
}

int main() {
  while ( input() ) {
    bool used[256];
    fill(used, used + 256, false);
    for ( const auto& c : S ) {
      used[tolower(c)] = true;
    }
    int cnt = 0;
    for ( char c = 'a'; c <= 'z'; ++ c ) {
      if ( used[c] ) {
        cnt ++;
      }
    }
    if ( cnt == 26 ) {
      cout << "pangram" << endl;
    } else {
      cout << "not pangram" << endl;
    }
  }
  return 0;
}
