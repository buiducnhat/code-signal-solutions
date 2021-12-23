int calSumOfDigits(int n ) {
    int sum = 0;
    while (n) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int solution(int n) {
    map<int, int> countDigit;
    while (n > 0) {
        int sumOfDigits = calSumOfDigits(n);
        countDigit[sumOfDigits]++;
        n -= sumOfDigits;
    }
    auto x = max_element(countDigit.begin(), countDigit.end(), [](pair<int, int> a, pair<int, int> b){
        return a.second == b.second ? a.first < b.first : a.second < b.second;
    });
    return (*x).first;
}
