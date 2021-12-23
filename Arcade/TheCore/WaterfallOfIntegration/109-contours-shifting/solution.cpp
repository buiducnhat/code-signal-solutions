vector<vector<int> > solution(vector<vector<int> > a)
{
    int y = a.size() - 1;
    int x = a[0].size() - 1;
    int m = min(a.size(), a[0].size()) + 1;
    for (int i = 0; i<m>> 1; i++) {
        int n = a[i][i];
        if (i & 1) {
            for (int j = i; j < x - i; j++) {
                a[i][j] = a[i][j + 1];
            }
            for (int j = i; j < y - i; j++) {
                a[j][x - i] = a[j + 1][x - i];
            }
            if (m & 1 || i != m / 2 - 1) {
                for (int j = x - i; j > i; j--) {
                    a[y - i][j] = a[y - i][j - 1];
                }
                for (int j = y - i; j > i; j--) {
                    a[j][i] = a[j - 1][i];
                }
                a[i + 1][i] = n;
            }
            else {
                a[y - i][x - i] = n;
            }
        }
        else {
            int o = a[y - i][x - i];
            if (m & 1 || i != m / 2 - 1) {
                for (int j = i; j < y - i; j++) {
                    a[j][i] = a[j + 1][i];
                }
                for (int j = i; j < x - i; j++) {
                    a[y - i][j] = a[y - i][j + 1];
                }
            }
            for (int j = y - i; j > i; j--) {
                a[j][x - i] = a[j - 1][x - i];
            }
            for (int j = x - i; j > i; j--) {
                a[i][j] = a[i][j - 1];
            }
            if (m & 1 || i != m / 2 - 1) {
                a[i][i + 1] = n;
            }
            else {
                a[i][i] = o;
            }
        }
    }
    return a;
}
