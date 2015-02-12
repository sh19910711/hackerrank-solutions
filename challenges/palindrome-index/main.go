package main

import "fmt"

type Solver struct {
  S string
  ind int
}

func (s *Solver) input() {
  fmt.Scanf("%s", &s.S)
}

func Reverse(s string) string {
  r := ""
  for _, c := range(s) {
    r = string(c) + r
  }
  return r
}

func IsPalindrome(s string) bool {
  for i, j := 0, len(s) - 1; i * 2 < len(s); i, j = i+1, j-1 {
    if s[i] != s[j] {
      return false
    }
  }
  return true
}

func find(s string) int {
  if IsPalindrome(s) {
    return -1
  }
  for k := range s {
    l := k
    r := len(s)-1-k
    if s[l] != s[r] {
      if IsPalindrome(s[0:l] + s[l+1:]) {
        return l
      } else {
        return r
      }
    }
  }
  return -2
}

func (s *Solver) solve() {
  s.ind = find(s.S)
}

func (s *Solver) output() {
  fmt.Printf("%d", s.ind)
  fmt.Println()
}

func main() {
  s := &Solver{}
  var t int
  fmt.Scanf("%d", &t)
  for t > 0 {
    s.input()
    s.solve()
    s.output()
    t -= 1
  }
}

