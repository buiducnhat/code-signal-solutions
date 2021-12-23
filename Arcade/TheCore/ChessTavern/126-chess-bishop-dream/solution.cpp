vector<int> solution(vector<int> bSize, vector<int> iPos, vector<int> dir, int k) {
    int h = bSize[0], w = bSize[1];
    int dRow = (iPos[0] + dir[0]*k + (long long) k*2*h) % (2*h);
    int dCol = (iPos[1] + dir[1]*k + (long long) k*2*w) % (2*w);

    return {dRow < h ? dRow : 2*h - dRow-1, dCol < w ? dCol : 2*w - dCol-1};
}
