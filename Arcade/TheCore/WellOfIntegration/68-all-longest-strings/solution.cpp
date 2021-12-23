vector<string> solution(vector<string> a) {
    int maxLength = 0;
    for (auto s : a) {
        maxLength = max(maxLength, (int)s.length());
    }
    
    vector<string> res;
    for (auto s : a) {
        if (s.length() == maxLength) {
            res.push_back(s);
        }
    }
    return res;
}
