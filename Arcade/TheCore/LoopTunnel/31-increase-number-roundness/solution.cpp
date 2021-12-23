bool solution(int n) {
    bool hasNot0Digit = false;
    int i = 0;
    while (n) {
        if (n%10 != 0) {
            hasNot0Digit = true;
        } else {
            if (hasNot0Digit) {
                return true;
            }
        }
        n /= 10;
        i++;
    }
    return false;
}
