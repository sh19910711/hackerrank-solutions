package main

import "fmt"
import "os"
import "bufio"
import "strings"

var buf = bufio.NewReader(os.Stdin)

type Input struct {
  eof bool
  s string
}

type Output struct {
  res bool
}

func readLine() (string, error) {
  b, _, err := buf.ReadLine()
  return string(b), err
}

func input() *Input {
  s, e := readLine()
  return &Input {
    s: s,
    eof: e != nil,
  }
}

func isPangram(s string) bool {
  strings.NewReader(s)
  var ok [256]bool
  for _, c := range(s) {
    ok[strings.ToLower(string(c))[0]] = true
  }
  for c := 'a'; c <= 'z'; c += 1 {
    if ! ok[c] {
      return false
    }
  }
  return true
}

func solve(i *Input) *Output {
  return &Output{res: isPangram(i.s)}
}

func output(o *Output) {
  if o.res {
    fmt.Println("pangram")
  } else {
    fmt.Println("not pangram")
  }
}

func main() {
  for in := input(); ! in.eof; in = input() {
    output(solve(in))
  }
}
