package main

import "fmt"

type Input struct {
  eof bool
  s string
}

type Output struct {
  res int
}

type Solver struct {
  in Input
  out Output
}

func max(a int, b int) int {
  if a > b {
    return a
  }
  return b
}

func (s *Solver) input() Input {
  _, err := fmt.Scanf("%s", &s.in.s)
  s.in.eof = s.in.eof || err != nil
  return s.in
}

func count(s string) []int {
  cnt := make([]int, 256)
  for _, c := range s {
    cnt[c] += 1
  }
  return cnt
}

func findMin(s string) int {
  if len(s) % 2 == 1 {
    return -1
  }
  s1 := s[0:len(s)/2]
  s2 := s[len(s)/2:]
  cnt1 := count(s1)
  cnt2 := count(s2)
  res := 0
  for c := 'a'; c <= 'z'; c += 1 {
    res += max(0, cnt1[c] - cnt2[c])
  }
  return res
}

func (s *Solver) solve() {
  s.out.res = findMin(s.in.s)
}

func (s *Solver) output() {
  fmt.Println(s.out.res)
}

func main() {
  s := new(Solver)
  var t int
  fmt.Scanf("%d", &t)
  for i := 0; i < t; i += 1 {
    if ! s.input().eof {
      s.solve()
      s.output()
    }
  }
}
