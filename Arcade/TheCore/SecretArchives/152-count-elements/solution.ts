function solution(s: string): number {
  const reg = /".*?"|true|false|\d+/gm;
  if (s.match(reg)) {
      return s.match(reg).length;
  }
  return 0;
}
