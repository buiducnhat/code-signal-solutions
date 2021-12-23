string solution(string s) {
    string res = "";
    int i = 0;
    while (i < s.length()){
        if (!isdigit(s[i])){
            return res;
        }
        res += s[i];
        i++;
    }
    return res;
}
