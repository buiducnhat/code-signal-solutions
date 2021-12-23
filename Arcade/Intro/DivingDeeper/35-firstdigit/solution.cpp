char solution(string inputString) {
    for (auto c : inputString) {
        if (isdigit(c)) {
            return c;
        }
    }
}
