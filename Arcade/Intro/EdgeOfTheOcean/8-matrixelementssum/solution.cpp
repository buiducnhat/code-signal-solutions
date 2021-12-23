int solution(vector<vector<int>> matrix) {
    int rowNum = matrix.size(), colNum = matrix[0].size();
    int cost = 0;
    
    vector<int> ghostRows;
    
    for (int j = 0; j < colNum; ++j) {
        for (int i = 0; i < rowNum; ++i) {
            if (matrix[i][j] == 0) {
                break;
            }
            cost += matrix[i][j];
        }
    }
    
    return cost;
}
