bool solution(vector<vector<int>> array1, vector<vector<int>> array2) {
    if (array1.size() != array2.size()) return false;
    for (int i = 0; i < array1.size(); i++) {
        if (array1[i].size() != array2[i].size()) return false;
    }
    return true;
}
