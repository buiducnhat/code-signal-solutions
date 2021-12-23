vector<vector<char>> solution(vector<vector<char>> canvas, vector<int> rectangle) {
    int x1=rectangle[0], y1=rectangle[1], x2=rectangle[2], y2=rectangle[3];
    // draw width
    for (int i = x1; i <= x2; i++) {
        canvas[y1][i] = canvas[y2][i] = '-';
    }
    // draw height
    for (int i = y1; i <= y2; i++) {
        canvas[i][x1] = canvas[i][x2] = '|';
    }
    // draw 4 vertexes
    canvas[y1][x1]=canvas[y1][x2]=canvas[y2][x1]=canvas[y2][x2]='*';
    return canvas;
}
