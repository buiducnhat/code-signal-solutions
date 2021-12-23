vector<int> solution(vector<string> rows) {
    int height = rows.size();
    map<int, int> count; // store column-time need to be motionless

    // fill a row of stones into the last of box
    rows.push_back(string(rows[0].size(), '#'));

    // for each column
    for (int i = 0; i < rows[0].size(); i++) {
        count[i] = 0;
        for (int j = 0; j < height; j++) {
            int k = 0;
            if (rows[j][i] == '#') {
                while (rows[j + k + 1][i] == '.') {
                    count[i]++;
                    k++;
                }
                j += k;
            }
        }
    }
    for (auto it = count.begin(); it != count.end(); it++) {
        cout << (*it).first << " - " << (*it).second << endl;
    }
    auto x = min_element(count.begin(), count.end(), [](pair<int, int> a, pair<int, int> b) {
        return a.second < b.second;
        });

    vector<int> res;
    for (auto c : count) {
        if (c.second == (*x).second) {
            res.push_back(c.first);
        }
    }

    return res;
}