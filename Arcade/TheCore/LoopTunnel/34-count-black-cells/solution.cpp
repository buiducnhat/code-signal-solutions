int solution(int n, int m) {
    return m + n + gcd(m, n) - 2;
}
