int solution(vector<int> inputArray) {
    int sum = 0;
    for (int i = 0; i < inputArray.size() && inputArray[i] != 0; i++) {
        sum += inputArray[i];
    }
    return sum;
}
