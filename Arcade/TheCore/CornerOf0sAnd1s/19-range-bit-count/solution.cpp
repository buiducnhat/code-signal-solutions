int solution(int a, int b) {
    int res = 0;
    for (int i = a; i <= b; ++i) {
        int k = i;
        while (k > 0) {
            res += k & 1;
            k = (k >> 1);
        }
    }
    return res;
}
