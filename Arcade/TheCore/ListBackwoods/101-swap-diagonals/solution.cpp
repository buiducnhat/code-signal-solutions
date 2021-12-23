vector<vector<int>> solution(vector<vector<int>> matrix) {
    int size = matrix.size();
    for (int i = 0; i < size; i++) {
        swap(matrix[i][i], matrix[i][size-i-1]);
    }
    return matrix;
}
