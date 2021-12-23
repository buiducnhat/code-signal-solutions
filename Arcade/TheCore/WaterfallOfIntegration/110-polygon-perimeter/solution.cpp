int solution(vector<vector<bool>> matrix) {
    vector<vector<bool>> a(matrix.size()+4, vector<bool>(matrix[0].size()+4, false));

    // Create another matrix (a) that has 2 layers of white cell
    // Solution: Count the black cell that is adjacent to the white cell from 1->size(a)-1
    for (int i = 2; i < a.size() - 2; i++) {
        for (int j = 2; j < a[0].size() - 2; j++) {
            a[i][j] = matrix[i-2][j-2];
        }
    }
    
    int count = 0;
    for (int i = 1; i < a.size() - 1; i++) {
        for (int j = 1; j < a[0].size() - 1; j++) {
            if (a[i][j] == false) {
                count += (a[i][j-1] + a[i-1][j] + a[i][j+1] + a[i+1][j]);
            }
        }
    }
    return count;
}
