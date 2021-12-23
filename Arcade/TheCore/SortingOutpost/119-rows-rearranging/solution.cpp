bool solution(vector<vector<int>> a) {
    for (int i = 0; i < a.size(); i++) {
        for (int j = 0; j < a.size(); j++) {
            if (i != j) {
                bool isGreater = a[i][0] > a[j][0];
                for (int k = 0; k < a[i].size(); k++) {
                    if (a[i][k] > a[j][k] != isGreater) {
                        return false;
                    }
                }
            }
        }
    }
    return true;
}
