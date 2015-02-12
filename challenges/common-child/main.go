package main

import "fmt"
import "io"

const SIZE = 5000 + 11

type Int int64
var EOF = io.EOF
var INPUT_END = &Input{eof: true}

type Input struct {
  eof bool
  a string
  b string
}

type Output struct {
  len Int
}

type Solver struct {
  in *Input
  out *Output
}

func (s *Solver) readWord(word *string) {
  _, err := fmt.Scan(word)
  if err == EOF {
    s.in = INPUT_END
  }
}

func (s *Solver) readWords(words ...*string) {
  for _, word := range words {
    s.readWord(word)
  }
}

func (s *Solver) input() *Input {
  s.readWords(&s.in.a, &s.in.b)
  return s.in
}

func (s *Solver) output() {
  fmt.Println(s.out.len)
}

func max(a Int, b Int) Int {
  if a > b {
    return a
  }
  return b
}

func findMax(a string, b string) Int {
  dp := make([][]Int, SIZE)
  for i := 0; i < SIZE; i += 1 {
    dp[i] = make([]Int, SIZE)
  }
  for i := 0; i < len(a); i += 1 {
    for j := 0; j < len(b); j += 1 {
      if a[i] == b[j] {
        dp[i+1][j+1] = dp[i][j] + 1
      } else {
        dp[i+1][j+1] = max(dp[i][j+1], dp[i+1][j])
      }
    }
  }
  return dp[len(a)][len(b)]
}

func (s *Solver) solve() {
  s.out.len = findMax(s.in.a, s.in.b)
}

func main() {
  s := &Solver {
    &Input{},
    &Output{},
  }
  for ! s.input().eof {
    s.solve()
    s.output()
  }
}
