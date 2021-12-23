int solution(int n, int l, int r) {
    if (2*l > n) return 0;
    if (2*r < n) return 0;
    l = max(l, n-r);
    return n / 2 - l + 1;
}
