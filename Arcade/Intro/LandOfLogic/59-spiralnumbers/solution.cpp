vector<vector<int>> solution(int n) {
    vector<vector<int>> a(n);
    vector<int> tmp(n);
    fill(a.begin(), a.end(), tmp);

    int c = 1, k = 0;
    while (c < n * n) {
        for (int j = k; j < n - k - 1; j++) {
            a[k][j] = c++;
        }
        for (int i = k; i < n - k - 1; i++) {
            a[i][n - k - 1] = c++;
        }
        for (int j = n - k - 1; j > k; j--) {
            a[n - k - 1][j] = c++;
        }
        for (int i = n - k - 1; i > k; i--) {
            a[i][k] = c++;
        }
        k++;
    }
    if (n & 1) a[n/2][n/2] = n*n;

    return a;
}