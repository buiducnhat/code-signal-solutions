string solution(string inputString) {
    for (auto &c:inputString) {
        c = 'z'-c+'a';
    }
    return inputString;
}
