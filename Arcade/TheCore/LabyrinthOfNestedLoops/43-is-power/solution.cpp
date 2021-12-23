bool solution(int n) {
    for (int b = 2; b <= 10; b++) {
        for (int a = 1; a <= 20; a++) {
            if (pow(a, b) == n) {
                return true;
            }
        }
    }
    return false;
}
