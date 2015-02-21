// @snippet <contest.go#0.0.4:package.go>
package main
// @snippet <contest.go#0.0.4:header/import.go>
import "fmt"
import "io"
import "os"
import "strings"

func Println(args ...interface{}) {
  fmt.Println(args...)
}

func Stdin() io.Reader {
  return os.Stdin
}

func Strin(s string) io.Reader {
  return strings.NewReader(s)
}
// @snippet <contest.go#0.0.4:header/typedef.go>
type Int int64
type IntSlice []Int
// @snippet <contest.go#0.0.4:utils/read.go>

func Read(a ...interface{}) bool {
  _, err := fmt.Fscan(in, a...)
  return err != io.EOF
}
// @snippet <contest.go#0.0.4:utils/stream.go>
var in io.Reader
// @snippet <contest.go#0.0.4:main.go>

type Solver struct {
  n Int
  s []string
}

func (s *Solver) input() bool {
  if Read(&s.n) {
    s.s = make([]string, s.n)
    for i := Int(0); i < s.n; i += 1 {
      Read(&s.s[i])
    }
    return true
  }
  return false
}

func (s *Solver) solve() Int {
  gem := make([]bool, 256)
  for i := 'a'; i <= 'z'; i += 1 {
    gem[i] = true
  }
  for i := Int(0); i < s.n; i += 1 {
    ok := make([]bool, 256)
    for _, c := range(s.s[i]) {
      ok[c] = true
    }
    for i := 'a'; i <= 'z'; i += 1 {
      gem[i] = gem[i] && ok[i]
    }
  }
  res := Int(0)
  for i := 'a'; i <= 'z'; i += 1 {
    if gem[i] {
      res += 1
    }
  }
  return res
}

func main() {
  in = Stdin()
  solver := new(Solver)
  for solver.input() {
    Println(solver.solve())
  }
}

