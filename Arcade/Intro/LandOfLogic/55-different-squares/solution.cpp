int solution(vector<vector<int>> matrix) {
    set<vector<vector<int>>> matrix2d;

    int rowCount = matrix.size(), colCount = matrix[0].size();
    vector<vector<int>> tmp(2);
    tmp[0] = {0,0};
    tmp[1] = {0,0};
    for (int i = 0; i < rowCount - 1; i++) {
        for (int j = 0; j < colCount - 1; j++) {
            tmp[0][0] = matrix[i][j];
            tmp[0][1] = matrix[i][j+1];
            tmp[1][0] = matrix[i+1][j];
            tmp[1][1] = matrix[i+1][j+1];
            matrix2d.insert(tmp);
        }
    }
    
    return matrix2d.size();
}
