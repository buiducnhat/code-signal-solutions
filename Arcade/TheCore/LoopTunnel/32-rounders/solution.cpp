int solution(int n) {
    int c = 1;
    while (n > 10) {
        n = (n + 5) / 10;
        c *= 10;
    }
    return n * c;   
}
