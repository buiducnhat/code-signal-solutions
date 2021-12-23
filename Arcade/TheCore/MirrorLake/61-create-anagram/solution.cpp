int solution(string s, string t) {
    int len=s.length(), cs[26] = {0}, ct[26] = {0};
    for (int i = 0; i < len; i++) {
        cs[s[i]-'A']++;
        ct[t[i]-'A']++;
    }
    int res = 0;
    for (int i = 0; i < 26; i++) {
        res += ct[i] ? ct[i] - cs[i] < 0 ? 0 : ct[i] - cs[i] : 0;
    }
    return res;
}
