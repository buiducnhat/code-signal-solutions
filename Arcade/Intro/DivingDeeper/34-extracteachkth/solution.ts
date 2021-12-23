function solution(a: number[], k: number): number[] {
  return a.filter((e, i) => (i + 1) % k !== 0);
}
