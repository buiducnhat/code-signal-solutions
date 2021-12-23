vector<int> solution(vector<int> a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] > a[i] && a[j] != -1 && a[i] != -1) {
                swap(a[i], a[j]);
            }
        }
    }
    
    return a;
}
