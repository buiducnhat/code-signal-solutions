vector<vector<int> > solution(vector<vector<bool> > matrix) {
    int rowNum = matrix.size(), colNum = matrix[0].size();
    // Reinput
    for (int i = 0; i < rowNum; i++) {
        matrix[i].insert(matrix[i].begin(), false);
        matrix[i].insert(matrix[i].end(), false);
    }
    vector<bool> boolTmp(colNum + 2);
    matrix.insert(matrix.begin(), boolTmp);
    matrix.insert(matrix.end(), boolTmp);

    vector<vector<int> > result(rowNum);
    vector<int> tmp(colNum);
    fill(result.begin(), result.end(), tmp);
    for (int i = 1; i < rowNum + 1; i++) {
        for (int j = 1; j < colNum + 1; j++) {
            result[i - 1][j - 1] += matrix[i - 1][j - 1] + matrix[i - 1][j] +
                matrix[i - 1][j + 1] + matrix[i][j - 1] + matrix[i][j] +
                matrix[i][j + 1] + matrix[i + 1][j - 1] +
                matrix[i + 1][j] + matrix[i + 1][j + 1];
            if (matrix[i][j]) {
                result[i - 1][j - 1]--;
            }
        }
    }

    return result;
}