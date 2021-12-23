int solution(int a, int b) {
    a /= sqrt(2);
    b /= sqrt(2);
    return 2 * a * b + a + b|1;
}
