string solution(string s) {
  stack<char> st;

  for (int i = 0; i < s.length(); ++i) {
    if (s[i] == '(') {
      st.push(i);
    } else if (s[i] == ')') {
      int pos = st.top();
      st.pop();
      reverse(s.begin() + pos + 1, s.begin() + i);
    }
  }

  auto pend = remove_if(s.begin(), s.end(),
                        [](char c) { return (c == '(' || c == ')'); });
  string res = "";
  for (auto it = s.begin(); it != pend; ++it)
    res += *it;

  return res;
}
