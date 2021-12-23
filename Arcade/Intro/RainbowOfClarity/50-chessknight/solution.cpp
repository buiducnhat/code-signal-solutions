bool isInBoard(string cell) {
    return cell[0] >= 'a' && cell[0] <= 'h' && cell[1] >= '1' && cell[1] <= '8';
}

int solution(string cell) {
    int count = 0;
    vector<pair<int, int>> steps = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};

    for (auto step : steps) {
        string tmp = cell;
        tmp[0] += step.first;
        tmp[1] += step.second;
        if (isInBoard(tmp)) {
            count++;
        }
    }

    return count;
}
