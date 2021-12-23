vector<string> solution(vector<string> names) {
    vector<string> res(names.begin(), names.end());
    set<string> unique;
    for (int i = 0; i < names.size(); i++) {
        if (unique.find(names[i]) == unique.end()) {
            unique.insert(res[i]);
        } else {
            int count = 1;
            while (unique.find(names[i] + "(" + to_string(count) + ")") != unique.end()) {
                count++;
            }
            res[i] = names[i] + "(" + to_string(count) + ")";
            unique.insert(res[i]);
        }
    }
    return res;
}
