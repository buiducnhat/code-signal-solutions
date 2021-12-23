vector<int> solution(vector<vector<int>> matrix, int column) {
    vector<int> res;
    for (int i = 0; i < matrix.size(); i++) {
        res.push_back(matrix[i][column]);
    }
    return res;
}
