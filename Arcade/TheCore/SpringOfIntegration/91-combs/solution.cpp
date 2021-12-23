int solution(string comb1, string comb2) {
    string c1 = comb1.size() >= comb2.size() ? comb1 : comb2, c2 = comb1.size() >= comb2.size() ? comb2 : comb1, c3;
    int rs = c1.size();
    vector<int> _c2;

    for (int i = 0; i < c2.size(); i++) {
        if (c2[i] == '*') _c2.push_back(i);
    }

    if (_c2.size() == 0) return c1.size();

    for (int _ = 0; _ <= c2.size(); _++) {
        for (int j = 0; j <= (c1.size() - c2.size()); j++) {
            bool ok = 1;
            for (int k = 0; k < _c2.size(); k++)
                if (c1[j + _c2[k]] != '.') ok = 0;
            if (ok) return rs;
        }
        c1 = '.' + c1 + '.'; rs++;
    }
}
