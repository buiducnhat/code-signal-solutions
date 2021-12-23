bool solution(std::string inputString) {
    int i = 0;
    for (auto c : inputString) {
        i++;
        if (i % 3 ? !isxdigit(c) : c != '-')
            return false;
    }
    return i == 17;
}
