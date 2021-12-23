int countDivisors(int n) {
    int count = 0;
    for (int i = 1; i <= sqrt(n); i++) {
        if (n % i == 0) {
            if (n / i == i)
                count++; 
            else
                count = count + 2;
        }
    }
    return count;
}

vector<int> solution(int n) {
    int numOfDivisor = countDivisors(n);
    // first: number of divisors. second: weakness
    vector<pair<int, int>> a(n+1);
    for (int i = 1; i <= n; ++i) {
        a[i].first = countDivisors(i);
        a[i].second = 0;
        for (int j = 1; j < i; j++) {
            if (a[j].first > a[i].first) {
                a[i].second++;
            }
        }
    }
    auto weaknest = *max_element(a.begin() + 1, a.end(), [](pair<int, int> i, pair<int, int> j) {
        return i.second < j.second;
    });
    int sameWeakness = count_if(a.begin()+1, a.end(), [weaknest](pair<int, int> cur) {
        return cur.second == weaknest.second;
    });
    return {weaknest.second, sameWeakness};
}
