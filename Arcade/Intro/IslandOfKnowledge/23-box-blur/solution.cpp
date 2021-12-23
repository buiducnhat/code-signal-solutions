vector <vector<int>> solution(vector<vector<int>> image) {
    int horSize = image.size(), verSize = image[0].size();
    vector < vector < int >> result;

    for (int i = 0; i < horSize - 2; ++i) {
        vector < int > horTmp;
        for (int j = 0; j < verSize - 2; ++j) {
            int sum = image[i][j] + image[i][j + 1] + image[i][j + 2] +
                image[i + 1][j] + image[i + 1][j + 1] + image[i + 1][j + 2] +
                image[i + 2][j] + image[i + 2][j + 1] + image[i + 2][j + 2];
            int avg = sum / 9;
            horTmp.push_back(avg);
        }
        result.push_back(horTmp);
    }
    
    return result;
}