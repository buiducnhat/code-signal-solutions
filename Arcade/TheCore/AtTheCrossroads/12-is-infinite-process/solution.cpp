bool solution(int a, int b) {
    return b<a || (abs(b-a)) & 1;
}
