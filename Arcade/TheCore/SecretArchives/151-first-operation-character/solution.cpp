int solution(string s) {
    int len = s.length();
    vector<pair<int, int>> pos;
    for (int i = 0; i < len; i++) {
        if (s[i] != '+' && s[i] != '*') continue;
        
        int count = 0;
        for (int j = 0; j < i; j++) {
            if (s[j] == '(') {
                count++;
            }
            if (s[j] == ')') {
                count--;
            }
        }
        count = max(count, 0);
        pos.push_back({i, count});
    }
    
    auto cmpOpe = [](char a, char b) -> bool{
        return a == '+' && b == '*' || a == b;
    };
    // for (auto x: pos) {
    //     cout << x.first << " " << s[x.first] << " " << x.second << endl;
    // }

    stable_sort(pos.begin(), pos.end(), [s, cmpOpe](pair<int, int> a, pair<int, int> b) {
       if (a.second == b.second) return cmpOpe(s[a.first], s[b.first]);
       return a.second < b.second;
    });
    // for (auto x: pos) {
    //     cout << x.first << " " << s[x.first] << " " << x.second << endl;
    // }
    return pos.back().first;
}
