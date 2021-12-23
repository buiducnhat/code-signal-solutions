bool solution(vector<vector<int>> grid) {
    set<int> oneToNine;

    // Check 9 rows
    int sum = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            oneToNine.insert(grid[i][j]);
        }
        if (oneToNine.size() != 9) return false;
        oneToNine.clear();
    }

    // Check 9 columns
    for (int j = 0; j < 9; j++) {
        for (int i = 0; i < 9; i++) {
            oneToNine.insert(grid[i][j]);
        }
        if (oneToNine.size() != 9) return false;
        oneToNine.clear();
    }
    
    // Check 9 sub grids
    for (int c = 0; c < 9; c++) {
        int row = c / 3, col = c % 3;
        for (int i = row * 3; i < row * 3 + 3; i++) {
            for (int j = col * 3; j < col * 3 + 3; j++) {
                oneToNine.insert(grid[i][j]);
            }
        }
        if (oneToNine.size() != 9) return false;
        oneToNine.clear();
    }

    return true;
}
