int solution(vector<int> a) {
    sort(a.begin(), a.end());
    int maxPos = a.back();
    
    for (int i = 1; i < maxPos + 2; i++) {
        bool isInvalid = false;
        for (int j = 0; j < a.size(); j++) {
            if (a[j] % i == 0) {
                isInvalid = true;
                break;
            }
        }
        if (!isInvalid) {
            return i;
        }
    }
    return maxPos + 1;
}
