int solution(vector<vector<int>> matrix, int a, int b) {
    int rowSum = accumulate(begin(matrix[a]), end(matrix[a]), 0);
    int colSum = accumulate(begin(matrix), end(matrix),0, [b]( int sum, vector<int> currRow){
        return sum + currRow[b];   
    });

    return rowSum + colSum - matrix[a][b];
}
