function solution(s) {
  return s.replace(/(\w+) (\w+)/g, "$2 $1");
}