vector<int> solution(vector<int> a) {
    vector<int> res(a.size(), -1);
    for (int i = 1; i < a.size(); i++) {
        for (int j = i-1; j >= 0; j--) {
            if (a[i] > a[j]) {
                res[i] = a[j];
                break;
            }
        }
    }
    return res;
}
