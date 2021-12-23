bool isValidSquareFormat(int n, int countChar[]) {
    int countDigit[10] = {0};
    while (n) {
        countDigit[n%10]++;
        n/=10;
    }
    sort(begin(countDigit), end(countDigit), greater<int>());
    for (int i = 0; i < 10; i++) {
        if (countDigit[i] != countChar[i]) {
            return false;
        }
    }
    return true;
}

int solution(string s) {
    int len = s.length(), maxPower10 = pow(10, len), minPower10 = pow(10, len-1);
    int countChar[256] = {0};
    for (auto c:s) countChar[c]++;
    sort(begin(countChar), end(countChar), greater<int>());

    for (int i = sqrt(maxPower10-1); i*i >= minPower10; --i) {
        if (isValidSquareFormat(i*i, countChar)){
            return i*i;
        }
    }
    return -1;
}
