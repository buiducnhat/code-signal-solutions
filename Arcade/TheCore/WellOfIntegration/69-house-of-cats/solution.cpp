vector<int> solution(int legs) {
    vector<int> res;
    for (int i = 0; i <= legs/2; i++) {
        for (int j = 0; j <= legs/2; j++) {
            if (i*2 + j*4 == legs) {
                res.push_back(i);
            }
        }
    }
    sort(res.begin(), res.end());
    return res;
}
