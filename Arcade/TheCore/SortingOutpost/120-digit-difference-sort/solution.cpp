vector<int> solution(vector<int> a) {
    auto findMaxDiffDigits = [](int n)->int {
        vector<int> digits;
        while (n) {
            digits.push_back(n%10);
            n/=10;
        }
        sort(digits.begin(), digits.end());
        return digits.back() - digits.front();
    };

    stable_sort(a.begin(), a.end(), [findMaxDiffDigits](int x, int y) {
       return findMaxDiffDigits(x) <= findMaxDiffDigits(y);
    });
    return a;
}
