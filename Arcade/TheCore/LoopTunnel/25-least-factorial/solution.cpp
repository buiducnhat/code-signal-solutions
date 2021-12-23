int solution(int n) {
    int k = 1, i = 1;
    while (k < n) {
        k *= i++;
    }
    return k;
}
