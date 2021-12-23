vector<vector<int>> solution(vector<vector<int>> matrix, int width, vector<int> center, int t) {
    int x = center[0], y=center[1];

    // array store 4 edges
    vector<vector<int>> edges(4);
    for (int i = 0; i < width; i++) {
        // 1st edge: {x, y-w} -> {x, y+w}
        edges[0].push_back(matrix[x][y-width/2+i]);
        // 2nd edge: {x-w, y-w} -> {x+w, y+w}
        edges[1].push_back(matrix[x-width/2+i][y-width/2+i]);
        // 3rd edge: {x-w, y} -> {x+w, y}
        edges[2].push_back(matrix[x-width/2+i][y]);
        // 4th edge: {x-w, y+w} -> {x+w, y-w}
        edges[3].push_back(matrix[x-width/2+i][y+width/2-i]);
    }
    
    t%=8;
    while (t--) {
        vector<int> tmpEdge = edges[3];
        reverse(tmpEdge.begin(), tmpEdge.end());
        edges[3] = edges[2],
        edges[2] = edges[1],
        edges[1] = edges[0],
        edges[0] = tmpEdge;
    }

    // restore edges to matrix
    for (int i = 0; i < width; i++) {
        // 1st edge: {x, y-w} -> {x, y+w}
        matrix[x][y-width/2+i] = edges[0][i];
        // 2nd edge: {x-w, y-w} -> {x+w, y+w}
        matrix[x-width/2+i][y-width/2+i] = edges[1][i];
        // 3rd edge: {x-w, y} -> {x+w, y}
        matrix[x-width/2+i][y] = edges[2][i];
        // 4th edge: {x+w, y-w} -> {x-w, y+w}
        matrix[x-width/2+i][y+width/2-i] = edges[3][i];
    }

    return matrix;
}
