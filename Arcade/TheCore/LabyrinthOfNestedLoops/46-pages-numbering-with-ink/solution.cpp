int countDigitOfNumber(int n) {
    int count = 0;
    while (n) {
        count++;
        n/=10;
    }
    return count;
}

int solution(int current, int numberOfDigits) {
    int c = countDigitOfNumber(current);
    while (numberOfDigits >= c) {
        current++;
        numberOfDigits -= c;
        c = countDigitOfNumber(current);
    }
    return current-1;
}
