int solution(vector<int> inputArray) {
    int res = 0;
    for (int i = 1; i < inputArray.size(); i++) {
        res = max(res, abs(inputArray[i] - inputArray[i-1]));
    }
    return res;
}
