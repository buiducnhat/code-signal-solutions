vector<string> solution(vector<string> t, vector<vector<int> > co) {
    vector<int> r, c;
    int x = 0, y = 0, tr, br, lc, rc;
    for (auto e : t) {
        if (e[0] == '+')
            r.push_back(x);
        x++;
    }
    for (auto e : t[0]) {
        if (e == '+')
            c.push_back(y); 
        y++;
    }
    tr = r[min(co[0][0], co[1][0])];
    br = r[max(co[0][0], co[1][0]) + 1];
    lc = c[min(co[0][1], co[1][1])];
    rc = c[max(co[0][1], co[1][1]) + 1];
    for (x = tr + 1; x < br; x++) {
        for (y = lc + 1; y < rc; y++) {
            if (t[x][y] == '-' || t[x][y] == '|' || t[x][y] == '+')
                t[x][y] = ' ';
            if (tr == 0)
                t[tr][y] = '-';
            if (br == t.size() - 1)
                t[br][y] = '-';
        }
        if (lc == 0)
            t[x][lc] = '|';
        if (rc == t[0].length() - 1)
            t[x][rc] = '|';
    }
    return t;
}
