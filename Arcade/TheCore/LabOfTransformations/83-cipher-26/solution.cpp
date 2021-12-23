string solution(string s) {
    string res = ""; res.push_back(s[0]);
    for (int i = 1; i < s.length(); i++) {
        int c = s[i] - s[i-1];
        int x = c>=0 ? c : c+26;
        res.push_back(x+'a');
    }
    return res;
}
