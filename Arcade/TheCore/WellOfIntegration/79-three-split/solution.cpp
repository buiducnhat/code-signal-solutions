int solution(vector<int> a) {
    int totalSum = accumulate(a.begin(), a.end(), 0, [](int f, int s) {
        return f + s;
    });
    int count = 0, firstSum = 0, secondSum = 0;
    for (int i = 0; i < a.size() - 2; i++) {
        firstSum += a[i];
        secondSum = 0;
        for (int j = i + 1; j < a.size() - 1; j++) {
            secondSum += a[j];
            if (firstSum == secondSum && secondSum == totalSum - firstSum - secondSum) {
                count++;
            }
        }
    }
    return count;
}
