bool solution(string inputString) {
    vector<int> counts(128);
    
    for (auto c:inputString) {
        counts[c]++;
    }
    
    int countOdd = 0;
    for (auto i:counts) {
        countOdd += i%2;
    }
    
    return countOdd <= 1;
}
