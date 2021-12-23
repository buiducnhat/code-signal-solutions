function solution(n: number): boolean {
  const s = n.toString().split("");
  return (
    s
      .slice(0, s.length / 2)
      .reduce((pre: string, cur: string) => (parseInt(pre) + parseInt(cur)).toString()) ===
    s
      .slice(s.length / 2, s.length)
      .reduce((pre: string, cur: string) => (parseInt(pre) + parseInt(cur)).toString())
  );
}
