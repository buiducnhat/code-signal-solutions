int solution(vector<int> a, int k) {
    int res = 0;
    for (int i = 0; i < a.size() - k + 1; ++i) {
        res = max(res, accumulate(a.begin() + i, a.begin() + i + k, 0));
    }
    return res;
}
