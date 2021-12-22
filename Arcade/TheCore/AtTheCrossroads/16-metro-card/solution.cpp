vector<int> solution(int lastNumberOfDays) {
    if (lastNumberOfDays < 31) return {31};
    if (lastNumberOfDays == 31) return {28, 30, 31};
}
