int sumDigit(int n) {
    int sum = 0;
    while (n) {
        sum += n%10;
        n /= 10;
    }
    return sum;
}

int solution(int n) {
    int hour = n/60, minute = n%60;
    return sumDigit(hour) + sumDigit(minute);
}
