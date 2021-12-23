bool solution(vector<vector<int> > shoes) {
    map<int, vector<int> > dict;
    for (auto shoe : shoes) {
        dict[shoe[1]].push_back(shoe[0]);
    }
    for (auto it : dict) {
        if (count(it.second.begin(), it.second.end(), 0) != it.second.size() / 2
            || count(it.second.begin(), it.second.end(), 1) != it.second.size() / 2) {
            return false;
        }
    }

    return true;
}
