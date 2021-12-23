// Tìm số có hiệu '(' - ')' lớn nhất
vector<int> solution(string tree) {
    vector<pair<int, int>> a;
    vector<int> res;
    int cur = 0;
    for (int i = 0; i < tree.length(); i++) {
        if (tree[i] == '(') {
            cur++;
            a.push_back({i, cur});
        }
        if (tree[i] == ')') {
            cur--;
            a.push_back({i, cur});
        }
    }

    int maxCount = 0;
    for (auto x: a) {
        if (isdigit(tree[x.first+1])) {
            maxCount = max(maxCount, x.second);
        }
    }
    for (auto x: a) {
        if (isdigit(tree[x.first+1]) && x.second == maxCount) {
            int i = x.first+1;
            string tmp = "";
            while (isdigit(tree[i])){
                tmp.push_back(tree[i]);
                ++i;
            }
            res.push_back(stoi(tmp));
        }
    }
    return res;
}
