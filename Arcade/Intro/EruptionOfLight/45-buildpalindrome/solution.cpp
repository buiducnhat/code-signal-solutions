string solution(string s) {
    int i = 0;
    while (s != string(s.rbegin(), s.rend())){
        s.insert(s.end() - i, s[i]);
        i++;    
    }
    return s;
}
