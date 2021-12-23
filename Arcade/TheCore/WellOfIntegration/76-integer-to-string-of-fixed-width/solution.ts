function solution(n: number, width: number): string {
  const s = n.toString().split('');
  while (s.length < width) {
      s.unshift('0');
  }
  while (s.length > width) {
      s.shift();
  }
  return s.join('');
}
