vector<int> solution(vector<int> a, vector<int> b) {
    a.insert(a.end(), b.begin(), b.end());
    return a;
}
