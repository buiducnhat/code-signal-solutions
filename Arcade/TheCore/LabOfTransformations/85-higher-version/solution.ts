function solution(ver1: string, ver2: string): boolean {
  const v1 = ver1.split('.').map(Number), v2 = ver2.split('.').map(Number);
  console.log(v1, v2);
  for (let i = 0; i < v1.length; i++) {
      if (v1[i] > v2[i]) {
          return true;
      } else if (v1[i] < v2[i]) {
          return false;
      }
  }
  return false;
}
