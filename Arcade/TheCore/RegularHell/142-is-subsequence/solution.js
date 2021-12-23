function solution(t, s) {
  let pattern = "";
  for (let i = 0; i < s.length; i++) {
    pattern += "["+s[i]+"]"+"+.*";
  }
  let re = new RegExp(pattern);
  return re.test(t);
}
