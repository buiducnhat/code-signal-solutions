vector<int> solution(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        if (a[i] == 1) {
            for (int j = 0; j <= i; j++) {
                a[j] = !a[j];
            }
        }
    }
    return a;
}
