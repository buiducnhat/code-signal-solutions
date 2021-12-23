vector<vector<int>> solution(vector<vector<int>> matrix) {
    int size = matrix.size();
    for (int i = 0; i < size/2; i++) {
        swap(matrix[i][i], matrix[size-i-1][size-i-1]);
        swap(matrix[i][size-i-1], matrix[size-i-1][i]);
    }
    return matrix;
}
