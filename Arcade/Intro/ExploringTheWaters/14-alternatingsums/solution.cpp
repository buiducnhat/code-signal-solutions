vector<int> solution(vector<int> a) {
    vector<int> result(2);
    for (int i = 0; i < a.size(); ++i) {
        result[i % 2] += a[i];
    }
    
    return result;
}
