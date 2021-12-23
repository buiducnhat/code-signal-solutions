string solution(string s) {
    string res = "";
    int i = 0, len = s.length();
    while (i < len) {
        string tmp = "";
        tmp.push_back(s[i]);
        i++;
        while (i < len && s[i] == tmp.back()) {
            tmp.push_back(s[i]);
            i++;
        }
        if (tmp.length() > 1) {
            res += to_string(tmp.length()) + tmp[0];
        } else {
            res += tmp[0];
        }
    }

    return res;
}
