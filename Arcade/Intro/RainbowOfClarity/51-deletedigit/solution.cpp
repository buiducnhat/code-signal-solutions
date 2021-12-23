int solution(int n) {
    string s = to_string(n);
    int res = 0;
    
    for (int i = 0; i < s.length(); i++ ) {
        string tmp = s;
        tmp.erase(tmp.begin() + i);
        res = max(res, stoi(tmp));
    }
    
    return res;
}
