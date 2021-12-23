int solution(vector<int> a) {
    int res = INT_MIN;
    for (int i = 0; i < a.size() - 1; i++) {
        res = max(res, a[i] * a[i + 1]);
    }
    return res;
}
