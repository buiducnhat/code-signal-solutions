vector<vector<string>> solution(vector<vector<string>> a, int k) {
    vector<string> p = {a[0][1], a[1][0], a[3][0], a[2][1], a[3][2], a[1][2]};
    k %= 6;
    while (k--) {
        string tmp = p[5];
        p[5]=p[4], p[4]=p[3], p[3]=p[2], p[2]=p[1], p[1]=p[0], p[0]=tmp;
    }
    a[0][1]=p[0], a[1][0]=p[1], a[3][0]=p[2], a[2][1]=p[3], a[3][2]=p[4], a[1][2]=p[5];
    return a;
}
