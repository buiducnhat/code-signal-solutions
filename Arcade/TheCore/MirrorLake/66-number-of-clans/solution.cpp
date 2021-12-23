int solution(vector<int> divisors, int k) {
    set<int> r;
    for (int i = 1; i <= k; i++) {
        int v = 0;
        for (auto d : divisors) {
            v = v*2 | (i % d == 0);
        }
        r.insert(v);
    }
    return r.size();
}
