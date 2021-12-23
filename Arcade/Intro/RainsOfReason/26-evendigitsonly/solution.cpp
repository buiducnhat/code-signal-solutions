bool solution(int n) {
    while (n) {
        int digit = n % 10;
        if (digit & 1) {
            return false;
        }
        n /= 10;
    }
    return true;
}
