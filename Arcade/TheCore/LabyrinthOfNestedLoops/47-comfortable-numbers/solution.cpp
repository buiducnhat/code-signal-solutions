int sumOfDigits(int n) {
    int sum = 0;
    while (n) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

bool isComfortablePair(int a, int b) {
    return b>=a-sumOfDigits(a) && b<=a+sumOfDigits(a) && a>=b-sumOfDigits(b) && a<=b+sumOfDigits(b);
}

int solution(int l, int r) {
    int count = 0;
    for (int a = l; a <= r-1; a++) {
        for (int b = a+1; b <= r; b++) {
            count += isComfortablePair(a, b);
        }
    }
    return count;
}
