function solution(s1: string, s2: string): boolean {
  // fill numeric values to 20 chars with leading zeros
  const x1 = s1.replace(/\d+/g, a => a.padStart(20, '0'))
  const x2 = s2.replace(/\d+/g, a => a.padStart(20, '0'))
  console.log(x1, x2)
  // check which is larger
  if (x1 < x2) return true
  if (x1 > x2) return false
  // if they are equal, fill strings with Z's and check again.
  return s1.padEnd(20, "Z") < s2.padEnd(20, "Z")
}
